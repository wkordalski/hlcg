#pragma once

#include "../assembly/build.hpp"

#include <vector>

namespace hlcg
{
  class Assembly;
  class Node
  {
  public:
    Node *parent;
    
    virtual ~Node() {}
  public:
    std::vector<Node *> attribs;
    
    virtual Assembly * assembly() { return parent->assembly(); }
    
  public:
    // Builds this node
    virtual void build(Build &b) = 0;
    // Clears build data from node
    virtual void clear() = 0;
  };
}