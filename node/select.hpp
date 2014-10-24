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
    virtual void build(Build &b);
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
    Member(Node *place, std::wstring name);
    
  public:
    virtual void build(Build &b);
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
    FindNamedNode(Node *place, std::wstring name);
    
  public:
    virtual void build(Build &b);
    virtual void clear();
    
    virtual std::vector<Node *> & get_selected() { return selected; }
    
  protected:
    std::vector<Node *> selected;
  };
}