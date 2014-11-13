#include "hlcg.hpp"

namespace hlcg {
  Handle Node::handle()
  {
    return {this->_id, this->_ass};
  }
  
  Assembly::Assembly()
  {
  }
  
  Node *Assembly::get_node ( Handle::type id )
  {
    auto it = this->_nodes.find(id);
    if(it != this->_nodes.end())
      return it->second;
    else
      return nullptr;
  }

  void Assembly::set_node ( Handle::type id, Node *node )
  {
    auto it = this->_nodes.find(id);
    if(it != this->_nodes.end())
    {
      Node *old = it->second;
      this->_nodes[id] = node;
      delete old;
    }
    else
    {
      this->_nodes[id] = node;
    }
  }
  
  Handle::type Assembly::new_node ( Node *node )
  {
    auto selected_id = _next_free_node;
    while(this->_nodes.count(selected_id) > 0) selected_id++;
    _next_free_node = selected_id + 1;
    
    this->set_node(selected_id, node);
    return selected_id;
  }
  
  Handle::Handle()
  {
    this->_id = 0;
    this->_ass = nullptr;
  }

  Handle::Handle ( Handle::type id, Assembly *assembly )
  {
    this->_id = id;
    this->_ass = assembly;
  }
  
  Node *Handle::get()
  {
    return _ass->get_node(_id);
  }

  bool Handle::valid()
  {
    return _id != 0 and _ass != nullptr;
  }
  
  void Handle::all ( std::function< void(Node *) > lambda )
  {
    if(valid()) lambda(this->get());
  }

  Node *Handle::operator->()
  {
    return this->get();
  }
  
  Node *Handle::operator()()
  {
    return this->get();
  }
  
  Handle &Handle::replace ( Node *node )
  {
    this->_ass->set_node(this->_id, node);
    return *this;
  }
}