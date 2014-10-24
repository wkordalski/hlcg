#include "template.hpp"

#include "description.hpp"

#include "../assembly/error.hpp"

namespace hlcg {
  Specialization::Specialization ( Node *templat, std::vector< Node * > params )
  {
  }

  void Specialization::build ( Build &b )
  {
    
    auto *sel = dynamic_cast<Selector *>(this->templ);
    if(sel == nullptr) throw new Error(this, "Template subnode is not a selector");
    templ->build(b);
    std::vector<Template *> templates;
    for(Node *n : sel->get_selected())
    {
      // should be a template
      auto *tpl = dynamic_cast<Template *>(n);
      // should be specializable
      if(tpl == nullptr) continue;
      templates.push_back(tpl);
    }
    
    // Prepare args...
  }

  void Specialization::clear()
  {
    selected.clear();
  }
}