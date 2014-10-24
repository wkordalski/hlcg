#pragma once

#include "../assembly/build.hpp"

#include <vector>

namespace hlcg
{
  class Node
  {
  public:
    Node *parent;
    
    virtual ~Node() {}
  public:
    std::vector<Node *> attribs;
    
  public:
    // Builds this node
    virtual void build(Build &b) = 0;
    // Clears build data from node
    virtual void clear() = 0;
  };
}