#pragma once

#include <vector>

namespace hlcg
{
  class Assembly;
  class Node
  {
  public:
    Node *parent;
    Assembly *assembly;
    bool is_built = false;
    
    virtual ~Node() {}
  public:
    std::vector<Node *> attribs;
    
  public:
    // Builds this node
    virtual void build() = 0;
    // Clears build data from node
    virtual void clear() = 0;
  };
}