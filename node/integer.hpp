#pragma once

#include "node.hpp"
#include "type.hpp"

namespace hlcg {
  class IntegerValue : public Node
  {
  public:
    std::vector<unsigned char> value;
    Node *type;
  };
  
  class SIntegerValue : public Node
  {
  public:
    std::vector<unsigned char> value;
    bool sign;
    Node *type;
  };
  
  class IntegerTemplate
  {
  };
  
  class IntegerType
  {
  };
}