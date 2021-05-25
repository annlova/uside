//
// Created by Anton on 2021-05-24.
//

#include "../h/shader_program_factory.h"

#include <logs/include/log_include.h>
#include <assertion/include/assertion_include.h>

#include "../h/shader_program_resource_factory.h"

void shader::ShaderProgramFactory::createShaderProgram(const char* vertexShaderSource, const char* fragmentShaderSource, const char* tessellationControlShaderSource, const char* tessellationEvaluationShaderSource, const char* geometryShaderSource, shader::ShaderProgram& out) {
    LOG_TRC() << "Creating shader program..." << LOG_END;
    ASSERT_MSG(vertexShaderSource != nullptr, "Vertex shader source must be supplied.");
    ASSERT_MSG(fragmentShaderSource != nullptr, "Fragment shader source must be supplied.");

    // Create shader program
    const GLuint programHandle = createProgram();

    // Create, compile, and attach the individual shaders
    // Vertex shader
    GLuint vertexShaderHandle = createShader(vertexShaderSource, GL_VERTEX_SHADER);
    attachShader(programHandle, vertexShaderHandle);

    // Fragment shader
    GLuint fragmentShaderHandle = createShader(fragmentShaderSource, GL_FRAGMENT_SHADER);
    attachShader(programHandle, fragmentShaderHandle);

    // Tessellation shaders
    GLuint tessellationControlShaderHandle = 0;
    GLuint tessellationEvaluationShaderHandle = 0;

    bool isTessellationControlShader = tessellationControlShaderSource;
    bool isTessellationEvaluationShader = tessellationEvaluationShaderSource;
    ASSERT_MSG(isTessellationControlShader == isTessellationEvaluationShader, "Either both or neither tessellation shader source have to be specified.");

    bool isTessellationShader = isTessellationControlShader && isTessellationEvaluationShader;
    if (isTessellationShader) {
        tessellationControlShaderHandle = createShader(tessellationControlShaderSource, GL_TESS_CONTROL_SHADER);
        tessellationEvaluationShaderHandle = createShader(tessellationEvaluationShaderSource, GL_TESS_EVALUATION_SHADER);

        attachShader(programHandle, tessellationControlShaderHandle);
        attachShader(programHandle, tessellationEvaluationShaderHandle);
    }

    // Geometry shader
    GLuint geometryShaderHandle = 0;

    if (geometryShaderSource != nullptr) {
        geometryShaderHandle = createShader(geometryShaderSource, GL_GEOMETRY_SHADER);
        attachShader(programHandle, geometryShaderHandle);
    }

    // Link the shader program object
    linkProgram(programHandle);

    // After linking the shader program object, detach and delete shader objects as they are no longer needed
    detachAndDeleteShaders(programHandle);

    createShaderProgram(programHandle, out);
}

void shader::ShaderProgramFactory::createShaderProgram(const char* vertexShaderSource, const char* fragmentShaderSource, shader::ShaderProgram& out) {
    createShaderProgram(vertexShaderSource, fragmentShaderSource, nullptr, nullptr, nullptr, out);
}

void shader::ShaderProgramFactory::createShaderProgram(const char* computeShaderSource, shader::ShaderProgram& out) {
    ASSERT_MSG(computeShaderSource != nullptr, "Compute shader source must be supplied.");

    // Create shader program
    const GLuint programHandle = createProgram();

    // Create and compile the compute shader
    GLuint computeShaderHandle = createShader(computeShaderSource, GL_COMPUTE_SHADER);

    // Attach compute shader to program
    attachShader(programHandle, computeShaderHandle);

    // Link program
    linkProgram(programHandle);

    // After linking the shader program, detach and delete the compute shader object as it is no longer needed
    detachAndDeleteShaders(programHandle);

    createShaderProgram(programHandle, out);
}

void shader::ShaderProgramFactory::createShaderProgram(GLuint programHandle, shader::ShaderProgram& out) {
    fillShaderProgramAttributes(programHandle, out);
    fillShaderProgramUniforms(programHandle, out);
    fillShaderProgramUniformBlocks(programHandle, out);
    fillShaderProgramShaderStorageBlocks(programHandle, out);
    out.mHandle = programHandle;
    LOG_TRC() << "ShaderProgram (" << programHandle << ") created." << LOG_END;
}

void shader::ShaderProgramFactory::fillShaderProgramAttributes(GLuint programHandle, shader::ShaderProgram& out) {
    // Get number of active attributes
    GLint numAttributes = getActiveResourceAmount(programHandle, GL_PROGRAM_INPUT);

    // Fill the ShaderProgram attributes array
    for (int attributeIndex = 0; attributeIndex < numAttributes; attributeIndex++) {
        static_cast<const void>(ShaderProgramResourceFactory::emplaceAttributeInMap(programHandle, attributeIndex, out.mAttributes));
    }
}

void shader::ShaderProgramFactory::fillShaderProgramUniforms(GLuint programHandle, shader::ShaderProgram& out) {
    // Variables to keep track of next free texture image unit and image unit
    GLint textureImageUnit = 0;
    GLint imageUnit = 0;

    // Variable for image format // TODO Set dependent on source code!
    GLint imageFormat = GL_RGB8;

    // Get number of active uniforms
    auto numUniforms = static_cast<GLuint>(getActiveResourceAmount(programHandle, GL_UNIFORM));

    // Variables to keep track of how many "pure" uniforms, samplers and images there have been
    GLuint numPureUniforms = 0;
    GLuint numSamplers = 0;
    GLuint numImages = 0;

    // Fill the ShaderProgram uniform, image and sampler arrays
    for (GLuint uniformIndex = 0; uniformIndex < numUniforms; uniformIndex++) {
        // If the uniform is apart of a uniform block skip it. It will be included in the uniform block representation
        if (ShaderProgramResourceFactory::isUniformIndexAUniformBlockVariable(programHandle, uniformIndex)) {
            continue;
        }

        // Retrieve what type of uniform this uniform index corresponds to and act thereafter
        auto type = ShaderProgramResourceFactory::getUniformType(programHandle, uniformIndex);
        switch (type) {
            case UNIFORM:
                fillShaderProgramPureUniform(programHandle, uniformIndex, out);
                numPureUniforms++;
                break;
            case SAMPLER:
                fillShaderProgramSampler(programHandle, uniformIndex, textureImageUnit, out);
                textureImageUnit++;
                numSamplers++;
                break;
            case IMAGE:
                fillShaderProgramImage(programHandle, uniformIndex, imageUnit, imageFormat, out);
                imageUnit++;
                numImages++;
                break;
            default:
                ASSERT_MSG(false, "Uniform type not supported!");
        }
    }
}

void shader::ShaderProgramFactory::fillShaderProgramPureUniform(GLuint programHandle, GLuint uniformIndex, shader::ShaderProgram& out) {
    static_cast<const void>(ShaderProgramResourceFactory::emplaceUniformInMap(programHandle, uniformIndex, out.mUniforms));
}

void shader::ShaderProgramFactory::fillShaderProgramSampler(GLuint programHandle, GLuint uniformIndex, GLint textureImageUnit, shader::ShaderProgram& out) {
    auto sampler = ShaderProgramResourceFactory::emplaceSamplerInMap(programHandle, uniformIndex, textureImageUnit, out.mSamplers);

    // Bind sampler to its texture image unit
    ASSERT_MSG(textureImageUnit < GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS, "Max amount of texture image units reached!");
    glProgramUniform1i(programHandle, sampler.mUniform.mLocation, textureImageUnit);
    ASSERT_GL();
}

void shader::ShaderProgramFactory::fillShaderProgramImage(GLuint programHandle, GLuint uniformIndex, GLint imageUnit, GLint imageFormat, shader::ShaderProgram& out) {
    auto image = ShaderProgramResourceFactory::emplaceImageInMap(programHandle, uniformIndex, imageUnit, imageFormat, out.mImages);

    // Bind image to its image unit
    ASSERT_MSG(imageUnit < GL_MAX_IMAGE_UNITS, "Max amount of image units reached!");
    glProgramUniform1i(programHandle, image.mUniform.mLocation, imageUnit);
    ASSERT_GL();
}

void shader::ShaderProgramFactory::fillShaderProgramUniformBlocks(GLuint programHandle, shader::ShaderProgram& out) {
    // Get number of active uniform blocks
    GLint numUniformBlocks = getActiveResourceAmount(programHandle, GL_UNIFORM_BLOCK);

    // Fill the ShaderProgram uniform blocks array
    for (int uniformBlockIndex = 0; uniformBlockIndex < numUniformBlocks; uniformBlockIndex++) {
        static_cast<const void> (ShaderProgramResourceFactory::emplaceShaderBlockInMap(programHandle, GL_UNIFORM_BLOCK, uniformBlockIndex, out.mUniformBlocks));
    }
}

void shader::ShaderProgramFactory::fillShaderProgramShaderStorageBlocks(GLuint programHandle, shader::ShaderProgram& out) {
    // Get number of active shader storage blocks
    GLint numShaderStorageBlocks = getActiveResourceAmount(programHandle, GL_SHADER_STORAGE_BLOCK);

    // Fill the ShaderProgram shader storage blocks array
    for (int shaderStorageBlockIndex = 0; shaderStorageBlockIndex < numShaderStorageBlocks; shaderStorageBlockIndex++) {
        static_cast<const void> (ShaderProgramResourceFactory::emplaceShaderBlockInMap(programHandle, GL_SHADER_STORAGE_BLOCK, shaderStorageBlockIndex, out.mShaderStorageBlocks));
    }
}

GLuint shader::ShaderProgramFactory::createShader(const GLchar* source, GLenum type) {
    ASSERT_MSG(typeIsShaderType(type), "The supplied type is not a shader type.");

    // Tell OpenGL we want to create a shader
    GLuint handle = glCreateShader(type);
    ASSERT_GL();

    // Load the source code into the shader
    const std::array<const GLchar*, 1> glShaderSourceInput{source};
    glShaderSource(handle, 1, glShaderSourceInput.data(), nullptr);
    ASSERT_GL();

    // Compile the shader with its source code
    glCompileShader(handle);
    ASSERT_GL();

    // Check if compilation was successful
    GLint status = 0;
    glGetShaderiv(handle, GL_COMPILE_STATUS, &status);
    ASSERT_GL();
    if (status == GL_FALSE) {
        // Fetch the shader info log
        GLsizei infoLogLength = 0;
        glGetShaderiv(handle, GL_INFO_LOG_LENGTH, &infoLogLength);
        ASSERT_GL();

        std::vector<GLchar> infoLog(infoLogLength);
        GLsizei infoLogLengthReturned = 0;
        glGetShaderInfoLog(handle, infoLogLength, &infoLogLengthReturned, infoLog.data());
        ASSERT_GL();
        ASSERT_MSG(infoLogLength == infoLogLengthReturned + 1, "The returned info log length was not the same as the queried length.");

        // Stringify the shader type for clearer error message
        const char* shaderTypeString = "UNKNOWN";
        switch (type) {
            case GL_COMPUTE_SHADER:
                shaderTypeString = "compute";
                break;
            case GL_VERTEX_SHADER:
                shaderTypeString = "vertex";
                break;
            case GL_TESS_CONTROL_SHADER:
                shaderTypeString = "tessellation control";
                break;
            case GL_TESS_EVALUATION_SHADER:
                shaderTypeString = "tessellation evaluation";
                break;
            case GL_GEOMETRY_SHADER:
                shaderTypeString = "geometry";
                break;
            case GL_FRAGMENT_SHADER:
                shaderTypeString = "fragment";
                break;
            default:
                ASSERT_MSG(false, "Unknown shader type!");
        }

        LOG_FTL() << "Compile failure in " << shaderTypeString << " shader: " << LOG_NL << infoLog.data() << LOG_END;
        exit(1); // TODO: Handle better?
    }

    return handle;
}

GLuint shader::ShaderProgramFactory::createProgram() {
    GLuint handle = glCreateProgram();
    ASSERT_GL();
    return handle;
}

void shader::ShaderProgramFactory::attachShader(GLuint programHandle, GLuint shaderHandle) {
    glAttachShader(programHandle, shaderHandle);
    ASSERT_GL();
}

void shader::ShaderProgramFactory::linkProgram(GLuint programHandle) {
    glLinkProgram(programHandle);
    ASSERT_GL();

    // Check if linkage was successful
    GLint status = 0;
    glGetProgramiv(programHandle, GL_LINK_STATUS, &status);
    ASSERT_GL();
    if (status == GL_FALSE) {
        // Fetch the shader info log
        GLsizei infoLogLength = 0;
        glGetProgramiv(programHandle, GL_INFO_LOG_LENGTH, &infoLogLength);
        ASSERT_GL();

        std::vector<GLchar> infoLog(infoLogLength);
        GLsizei infoLogLengthReturned = 0;
        glGetProgramInfoLog(programHandle, infoLogLength, &infoLogLengthReturned, infoLog.data());
        ASSERT_GL();
        ASSERT_MSG(infoLogLength == infoLogLengthReturned + 1, "The returned info log length was not the same as the queried length.");

        LOG_FTL() << "Linkage failure in shader program (" << programHandle << "):" << LOG_NL << infoLog.data() << LOG_END;
        exit(1);
    }
}

void shader::ShaderProgramFactory::detachAndDeleteShaders(GLuint programHandle) {
    // Check that all attached shaders fit into the attached shader handles array
    GLsizei numAttachedShaderHandles = 0;
    glGetProgramiv(programHandle, GL_ATTACHED_SHADERS, &numAttachedShaderHandles);
    ASSERT_GL();

    // Get attached shaders
    std::vector<GLuint> attachedShaderHandles(numAttachedShaderHandles);
    GLsizei numAttachedShaderHandlesReceived = 0;
    glGetAttachedShaders(programHandle, numAttachedShaderHandles, &numAttachedShaderHandlesReceived, attachedShaderHandles.data());
    ASSERT_GL();

    ASSERT_MSG(numAttachedShaderHandles == numAttachedShaderHandlesReceived, "Number of attached shaders received for detaching and deletion did not match amount queried.");

    // Detach and delete shaders
    for (int i = 0; i < numAttachedShaderHandles; i++) {
        glDetachShader(programHandle, attachedShaderHandles[i]);
        ASSERT_GL();
        glDeleteShader(attachedShaderHandles[i]);
        ASSERT_GL();
    }
}

GLint shader::ShaderProgramFactory::getActiveResourceAmount(GLuint programHandle, GLenum programInterface) {
    GLint activeResourceAmount = 0;
    glGetProgramInterfaceiv(programHandle, programInterface, GL_ACTIVE_RESOURCES, &activeResourceAmount);
    ASSERT_GL();

    return activeResourceAmount;
}

bool shader::ShaderProgramFactory::typeIsShaderType(GLenum type) {
    switch (type) {
        case GL_COMPUTE_SHADER:
        case GL_VERTEX_SHADER:
        case GL_TESS_CONTROL_SHADER:
        case GL_TESS_EVALUATION_SHADER:
        case GL_GEOMETRY_SHADER:
        case GL_FRAGMENT_SHADER:
            return true;
        default:
            return false;
    }
}
