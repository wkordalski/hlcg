#pragma once

#include "../node/node.hpp"

#include <exception>

namespace hlcg
{
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