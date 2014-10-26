#pragma once

#include "node.hpp"

#include <vector>

namespace hlcg {
  class Specialization : public Node
  {
  public:
    Node *templ;
    std::vector<Node *> params;
    
  public:
    Specialization( hlcg::Assembly *ass, hlcg::Node *templat, std::vector< hlcg::Node * > params = {} );
    
  public:
    virtual void build();
    virtual void clear();
    
    virtual bool is_selector() { return true; }
    virtual std::vector<Node *> * get_selected() { return &selected; }
    
  protected:
    std::vector<Node *> selected;
  };
}