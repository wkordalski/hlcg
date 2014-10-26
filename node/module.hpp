#pragma once

// HLCG headers
#include "node.hpp"
#include "description.hpp"

// Standard library headers
#include <string>
#include <vector>

namespace hlcg
{
  class Module : public Node, public Container
  {
  public:
    // Module name
    std::wstring name;
    // Members in the module
    std::vector<Node *> members;
    
  public:
    Module(Assembly *ass, std::wstring name);
    
    virtual void build();
    virtual void clear();
    
  public:
    // Container
    virtual std::vector<Node *> & get_members() { on_get_members(this); return members; }
    virtual std::vector<Node *> get_member_by_name(std::wstring name);
  };
}