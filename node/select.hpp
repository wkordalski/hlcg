/*
 * Node selection routines
 */

#pragma once

#include "node.hpp"
#include "description.hpp"

namespace hlcg {
  class Global : public Node, public Selector
  {
  public:
    // No params or childs
    
  public:
    Global(Assembly *ass);
    
    virtual void build();
    virtual void clear();
    
    virtual std::vector<Node *> & get_selected() { return selected; }
    
  protected:
    // Build results
    std::vector<Node *> selected;
    
  };
  
  class Member : public Node
  {
  public:
    std::wstring name;
    Node *place;
    
  public:
    Member(Assembly *ass, Node *place, std::wstring name);
    
  public:
    virtual void build();
    virtual void clear();
    
    
    virtual std::vector<Node *> & get_selected() { return selected; }
    
  protected:
    // Build results
    std::vector<Node *> selected;
  };
  
  class FindNamedNode : public Node
  {
  public:
    std::wstring name;
    Node *place;
    
  public:
    FindNamedNode(Assembly *ass, Node *place, std::wstring name);
    
  public:
    virtual void build();
    virtual void clear();
    
    virtual std::vector<Node *> & get_selected() { return selected; }
    
  protected:
    std::vector<Node *> selected;
  };
}