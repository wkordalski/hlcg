#include "select.hpp"

#include "module.hpp"
#include "../assembly/assembly.hpp"
#include "../assembly/error.hpp"

namespace hlcg {
  Global::Global ( Assembly *ass )
  {
    this->assembly = ass;
  }

  void Global::build()
  {
    this->selected.reserve(assembly->modules.size() + assembly->depmods.size());
    for(auto m : assembly->modules)
      this->selected.push_back(m);
    for(auto m : assembly->depmods)
      this->selected.push_back(m);
  }

  void Global::clear()
  {
    this->selected.clear();
  }

  Member::Member ( Assembly *ass, Node *place, std::wstring name )
  {
    this->assembly = ass;
    this->name = name;
    this->place = place;
  }
  
  void Member::build()
  {
    if(is_built) return;
    auto *selector = dynamic_cast<Selector*>(this->place);
    if(selector == nullptr) throw Error(this, "place is not a selector");
    
    this->place->build();
    for(Node *m : selector->get_selected())
    {
      auto *container = dynamic_cast<Container*>(m);
      if(container == nullptr) continue;
      
      for(Node *n : container->get_member_by_name(name))
      {
	this->selected.push_back(n);
      }
    }
  }
  
  void Member::clear()
  {
    this->selected.clear();
  }

  FindNamedNode::FindNamedNode ( Assembly *ass, Node *place, std::wstring name )
  {
    this->assembly = ass;
    this->name = name;
    this->place = place;
  }

  void FindNamedNode::build()
  {
    // TODO: do lookup for named nodes
  }

  void FindNamedNode::clear()
  {
    this->selected.clear();
  }
}