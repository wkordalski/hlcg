#pragma once

#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>

namespace hlcg
{
  class Assembly;
  
  struct Build
  {
    llvm::LLVMContext *ctx;
    llvm::Module *mod;
    Assembly *ass;
  };
}