/*
 * Licensing info
 * 
 */

/*
 * Top-level header file for HLCG
 */

#pragma once

#include <exception>
#include <unordered_map>
#include <vector>

#include <llvm/IR/Module.h>
#include <llvm/IR/LLVMContext.h>

namespace hlcg
{
  /*
   * Forward declarations
   */
  class Assembly;
  class Node;
  class Handle;
  
  /*
   * Represents a node in the AST
   */
  class Node
  {
    int         _id;
    Assembly *  _ass;
  public:
    virtual ~Node() {}
    
    Handle handle ();
  };
  
  /*
   * Represents a handle to the node
   */
  class Handle
  {
    typedef int type;
    type         _id;
    Assembly *   _ass;
  public:
    Handle();
    
    Node * get();
    bool valid();
    
    // Runs if T is matched
    template<typename T>
    Handle match(std::function<void(T*)> lambda)
    {
      if(this->valid() == false) return *this;
      
      T* r = dynamic_cast<T*>(this->get());
      if(r != nullptr)
      {
	lambda(r);
	return {0, _ass};
      }
      else
      {
	return *this;
      }
    }
    
    // Runs if type is correct
    void all(std::function<void(Node *)> lambda);
    
    Node * operator -> ();
    Node * operator () ();
    
    Handle & replace(Node *node);
    
  protected:
    Handle(type id, Assembly *assembly);
    friend class Node;
    friend class Assembly;
  };
  
  /*
   * The top of the AST
   */
  class Assembly
  {
    
    /* NODE MANAGEMENT */
  protected:
    std::unordered_map<Handle::type, Node *> _nodes;
    Handle::type _next_free_node;

  protected:    
    Node * get_node(Handle::type id);
    void set_node(Handle::type id, Node * node);
    Handle::type new_node(Node *node);
    
    friend class Handle;
    
    /* MODULE MANAGEMENT */
  protected:
    std::vector<Handle> _modules;
    std::vector<Handle> _dep_modules;
    
    void resolve_dependencies();
    
    /* LLVM SUBSYSTEM */
  protected:
    llvm::LLVMContext *ctx;
    llvm::Module *mod;
    
    
    /* PUBLIC */
  public:
    Assembly();
    
    template<typename T, typename... Args>
    Handle allocate(Args... args)
    {
      return {this->new_node(new T(args...)), this};
    }
  };
  
  
  
  class Error : public std::exception
  {
    Node *_node;
    std::string _msg;
  public:
    Error(Node *n, std::string message) : _node(n), _msg(message) {}
    
    Node * node() { return _node; }
    std::string message() { return _msg; }
  };
}