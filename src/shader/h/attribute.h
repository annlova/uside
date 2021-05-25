//
// Created by anton on 2021-05-23.
//

#ifndef USIDE_SRC_SHADER_H_ATTRIBUTE_H
#define USIDE_SRC_SHADER_H_ATTRIBUTE_H

#include <cstdint>
#include <array>
#include <string>

#include <glad/glad.h>

namespace shader {
    struct Attribute {
        GLuint mIndex;
        std::uint64_t mHashedName;

        GLint mNameLength;
        GLint mType;
        GLint mArraySize;
        GLint mReferencedByVertex;
        GLint mReferencedByTessellationControl;
        GLint mReferencedByTessellationEvaluation;
        GLint mReferencedByGeometry;
        GLint mReferencedByFragment;
        GLint mReferencedByCompute;
        GLint mLocation;
        GLint mIsPerPatch;
        GLint mLocationComponent;

        std::string mName;

        /** List of all property types of an attribute.
        *  OBS! The order here must be the same as the
        *  order declared of the corresponding variables. */
        static constexpr const std::array<GLenum, 12> mscProperties {
                GL_NAME_LENGTH,
                GL_TYPE,
                GL_ARRAY_SIZE,
                GL_REFERENCED_BY_VERTEX_SHADER,
                GL_REFERENCED_BY_TESS_CONTROL_SHADER,
                GL_REFERENCED_BY_TESS_EVALUATION_SHADER,
                GL_REFERENCED_BY_GEOMETRY_SHADER,
                GL_REFERENCED_BY_FRAGMENT_SHADER,
                GL_REFERENCED_BY_COMPUTE_SHADER,
                GL_LOCATION,
                GL_IS_PER_PATCH,
                GL_LOCATION_COMPONENT
        };
    };
}
#endif //USIDE_SRC_SHADER_H_ATTRIBUTE_H
