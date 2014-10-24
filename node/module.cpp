#include "module.hpp"

namespace hlcg {
  Module::Module ( std::wstring name )
  {
    this->name = name;
  }
  
  void Module::build(Build &b)
  {
  }

  void Module::clear()
  {
  }
}