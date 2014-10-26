#pragma once

// HLCG headers
#include "../node/module.hpp"

// Standard library headers
#include <map>
#include <vector>

// LLVM library headers
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>

namespace hlcg
{
  class Global;
  
  class Assembly
  {
  public:
    // Modules to be built
    std::vector<Module *> modules;
    
  protected:
    // Modules as dependencies
    // (can be removed with GC, etc.)
    std::vector<Module *> depmods;
    
  public:
    Assembly();
    // Builds modules
    void build();
    void clear();

    // LLVM module
    llvm::LLVMContext *ctx;
    llvm::Module *mod;
    
  protected:
    // Loads required modules
    void resolve_dependencies();
    
    friend class hlcg::Global;
  };
}