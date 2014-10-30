#pragma once

#include "node.hpp"
#include "description.hpp"

namespace hlcg {
  class IntegerValue : public Node, public CTValue
  {
  public:
    std::vector<unsigned char> value;
    Node *type;
  };
  
  class SIntegerValue : public Node, public CTValue
  {
  public:
    std::vector<unsigned char> value;
    bool sign;
    Node *type;
  };
  
  class IntegerTemplate : public Node, public Template
  {
  public:
    Node *parent;
    Assembly *assembly;
    
  public:
    IntegerTemplate (); // TODO
    
    Node * specialize(std::vector<Node *> params);
    
    
    void build();
    void clear();
    
  protected:
    std::vector<std::pair<std::vector<Node *>, Node *>> specializations;
  };
  
  class SIntegerTemplate : public Node, public Template
  {
  public:
    Node *parent;
    Assembly *assembly;
    
  public:
    SIntegerTemplate (); // TODO
  };
  
  class IntegerType : public Node
  {
  };
}