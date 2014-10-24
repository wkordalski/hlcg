#pragma once

// HLCG headers
#include "build.hpp"
#include "../node/module.hpp"

// Standard library headers
#include <map>
#include <vector>

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
    // Builds modules
    Build build();
    void clear();
    
  protected:
    // Loads required modules
    void resolve_dependencies();
    
    friend class hlcg::Global;
  };
}