#include "module.hpp"

namespace hlcg {
  Module::Module ( hlcg::Assembly *ass, std::wstring name )
  {
    this->assembly = ass;
    this->name = name;
  }
  
  void Module::build()
  {
  }

  void Module::clear()
  {
  }
  
  std::vector< Node * > Module::get_member_by_name ( std::wstring name )
  {
    on_get_member_by_name(this, name);
    std::vector<Node *> ret;
    for(Node *n : members)
    {
      auto *nm = dynamic_cast<Named *>(n);
      if(nm == nullptr) continue;
      if(nm->get_name() == name)
	ret.push_back(n);
    }
    return ret;
  }

}