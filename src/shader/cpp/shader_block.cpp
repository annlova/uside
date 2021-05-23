//
// Created by anton on 2021-05-23.
//

#include "../h/shader_block.h"

shader::ShaderBlock::ShaderBlock()
   : mIndex{},
     mHashedName{},
     mNameLength{},
     mBufferBinding{},
     mBufferDataSize{},
     mNumActiveVariables{},
     mReferencedByVertex{},
     mReferencedByTessellationControl{},
     mReferencedByTessellationEvaluation{},
     mReferencedByGeometry{},
     mReferencedByFragment{},
     mReferencedByCompute{},
     mActiveVariables{} {}
