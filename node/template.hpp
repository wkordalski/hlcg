#pragma once

#include "node.hpp"
#include "description.hpp"

#include <vector>

namespace hlcg {
  
  // Represents a template parameter
  // which is a Compile-time value
  class TemplateValueHolder : public Node, public TemplateParamHolder
  {
  };
  
  // Represents a template parameter
  // which is a Type
  class TemplateTypeHolder : public Node, public TemplateParamHolder
  {
  };
  
  // Specialization
  // It can get EVERY correct node
  // Class specialization is simple replacement of nodes holders with real nodes
  class Specialization : public Node,  public Selector
  {
  public:
    Node *templ;
    std::vector<Node *> params;
    
  public:
    Specialization( hlcg::Assembly *ass, hlcg::Node *templat, std::vector< hlcg::Node * > params = {} );
    
  public:
    virtual void build();
    virtual void clear();
    
    virtual std::vector<Node *> & get_selected() { return selected; }
    
  protected:
    // Selects only one node!!! - Else - ambiguity error.
    std::vector<Node *> selected;
  };
}