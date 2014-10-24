#pragma once

// HLCG headers
#include "node.hpp"
#include "description.hpp"

// Standard library headers
#include <string>
#include <vector>

namespace hlcg
{
  class Module : public Node//, public Container
  {
  public:
    // Module name
    std::wstring name;
    // Members in the module
    std::vector<Node *> members;
    
  public:
    Module(std::wstring name);
    
    virtual void build(Build &b);
    virtual void clear();
  };
}