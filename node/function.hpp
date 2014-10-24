#pragma once

#include "node.hpp"

#include <string>

namespace hlcg
{
  class Function : public Node, public Named
  {
  public:
    Node *type;
    Node *body;
  };
}
