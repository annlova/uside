//
// Created by anton on 2021-05-23.
//

#ifndef USIDE_SRC_SHADER_H_UNIFORM_H
#define USIDE_SRC_SHADER_H_UNIFORM_H

#include <cstdint>
#include <array>
#include <string>

#include <glad/glad.h>

namespace shader {

    struct Uniform {
        GLuint mIndex;
        std::uint64_t mHashedName;

        GLint mNameLength;
        GLint mType;
        GLint mArraySize;
        GLint mOffset;
        GLint mBlockIndex;
        GLint mArrayStride;
        GLint mMatrixStride;
        GLint mAtomicCounterBufferIndex;
        GLint mIsRowMajor;
        GLint mReferencedByVertex;
        GLint mReferencedByTessellationControl;
        GLint mReferencedByTessellationEvaluation;
        GLint mReferencedByGeometry;
        GLint mReferencedByFragment;
        GLint mReferencedByCompute;
        GLint mLocation;

        std::string mName;

        /** List of all property types of a uniform.
        *  OBS! The order here must be the same as the
        *  order declared of the corresponding variables. */
        static constexpr std::array<GLenum, 16> mscProperties {
                GL_NAME_LENGTH,
                GL_TYPE,
                GL_ARRAY_SIZE,
                GL_OFFSET,
                GL_BLOCK_INDEX,
                GL_ARRAY_STRIDE,
                GL_MATRIX_STRIDE,
                GL_ATOMIC_COUNTER_BUFFER_INDEX,
                GL_IS_ROW_MAJOR,
                GL_REFERENCED_BY_VERTEX_SHADER,
                GL_REFERENCED_BY_TESS_CONTROL_SHADER,
                GL_REFERENCED_BY_TESS_EVALUATION_SHADER,
                GL_REFERENCED_BY_GEOMETRY_SHADER,
                GL_REFERENCED_BY_FRAGMENT_SHADER,
                GL_REFERENCED_BY_COMPUTE_SHADER,
                GL_LOCATION
        };

        /**
         * Checks if given glType is a sampler glType.
         * @param glType - GL glType constant to check.
         * @return True if given glType is a sampler glType.
         */
        static bool glTypeIsUniform(GLint glType);
    };
}
#endif //USIDE_SRC_SHADER_H_UNIFORM_H
