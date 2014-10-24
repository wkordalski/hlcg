/*
 * Describing nodes
 */

#pragma once

#include "node.hpp"

#include <vector>

namespace hlcg {
  class Selector
  {
  public:
    virtual std::vector<Node *> & get_selected() = 0;
  };
  
  class Named
  {
  public:
    virtual std::wstring & get_name() = 0;
  };
  
  class Container
  {
  public:
    virtual std::vector<Node *> & get_members() = 0;
  };
  
  class Template
  {
  public:
    // TODO
  };
}