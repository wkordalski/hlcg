#include "select.hpp"

#include "module.hpp"
#include "../assembly/assembly.hpp"
#include "../assembly/error.hpp"

namespace hlcg {
  void Global::build ( Build &b )
  {
    this->selected.reserve(b.ass->modules.size() + b.ass->depmods.size());
    for(auto m : b.ass->modules)
      this->selected.push_back(m);
    for(auto m : b.ass->depmods)
      this->selected.push_back(m);
  }

  void Global::clear()
  {
    this->selected.clear();
  }

  Member::Member ( Node *place, std::wstring name )
  {
    this->name = name;
    this->place = place;
  }
  
  void Member::build ( Build &b )
  {
    auto *selector = dynamic_cast<Selector*>(this->place);
    if(selector == nullptr) throw Error(this, "place is not a selector");
    
    this->place->build(b);
    for(Node *m : selector->get_selected())
    {
      auto *container = dynamic_cast<Container*>(m);
      if(container == nullptr) continue;
      
      for(Node *n : container->get_members())
      {
	auto *named = dynamic_cast<Named *>(n);
	if(named == nullptr) continue;
	if(named->get_name() == this->name)
	  this->selected.push_back(n);
      }
    }
  }
  
  void Member::clear()
  {
    this->selected.clear();
  }

  FindNamedNode::FindNamedNode ( Node *place, std::wstring name )
  {
    this->name = name;
    this->place = place;
  }

  void FindNamedNode::build ( Build &b )
  {
    // TODO: do lookup for named nodes
  }

  void FindNamedNode::clear()
  {
    this->selected.clear();
  }
}