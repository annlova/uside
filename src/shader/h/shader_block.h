//
// Created by anton on 2021-05-23.
//

#ifndef USIDE_SRC_SHADER_H_SHADER_BLOCK_H
#define USIDE_SRC_SHADER_H_SHADER_BLOCK_H

#include <cstdint>
#include <array>
#include <vector>
#include <string>

#include "active_variable.h"

namespace shader {
    struct ShaderBlock {
        GLuint mIndex;
        std::uint64_t mHashedName;

        GLint mNameLength;
        GLint mBufferBinding;
        GLint mBufferDataSize;
        GLint mNumActiveVariables;
        GLint mReferencedByVertex;
        GLint mReferencedByTessellationControl;
        GLint mReferencedByTessellationEvaluation;
        GLint mReferencedByGeometry;
        GLint mReferencedByFragment;
        GLint mReferencedByCompute;

        std::vector<ActiveVariable> mActiveVariables{};

        std::string mName;

        /** List of all property types of a uniform.
        *  OBS! The order here must be the same as the
        *  order declared of the corresponding variables. */
        static constexpr std::array<GLenum, 10> mscProperties {
                GL_NAME_LENGTH,
                GL_BUFFER_BINDING,
                GL_BUFFER_DATA_SIZE,
                GL_NUM_ACTIVE_VARIABLES,
                GL_REFERENCED_BY_VERTEX_SHADER,
                GL_REFERENCED_BY_TESS_CONTROL_SHADER,
                GL_REFERENCED_BY_TESS_EVALUATION_SHADER,
                GL_REFERENCED_BY_GEOMETRY_SHADER,
                GL_REFERENCED_BY_FRAGMENT_SHADER,
                GL_REFERENCED_BY_COMPUTE_SHADER,
                // GL_ACTIVE_VARIABLES must be treated separately to account for vector resizing
        };
    };
}
#endif //USIDE_SRC_SHADER_H_SHADER_BLOCK_H
