#include "template.hpp"

#include "description.hpp"

#include "../assembly/error.hpp"

namespace hlcg {
  Specialization::Specialization ( Assembly *ass, Node *templat, std::vector< Node * > params )
  {
    this->assembly = ass;
    this->templ = templat;
    this->params = params;
  }

  void Specialization::build ( )
  {
    
    auto *sel = dynamic_cast<Selector *>(this->templ);
    if(sel == nullptr) throw new Error(this, "Template subnode is not a selector");
    templ->build();
    std::vector<Template *> templates;
    for(Node *n : sel->get_selected())
    {
      auto *tpl = dynamic_cast<Template *>(n);
      // should be template
      if(tpl == nullptr) continue;
      // we can't pass more params then template can get...
      if(tpl->declaration().size() < params.size()) continue;
      templates.push_back(tpl);
    }
    
    // Prepare args...
    for(Node *n : this->params)
    {
      n->build();
    }
    
    // Do some complicated algorithm to use proper template.
    // No... Let's simply try to find matching patterns.
    for(Template *n : templates)
    {
      auto decl = n->declaration();
      int idx = 0;
      for(Node * m : decl)
      {
	auto holder = dynamic_cast<TemplateParamHolder *>(m);
	if(holder == nullptr) throw new Error(this, "Template declaration should be a list of TemplateParamHolders");
	// Let's try to match the nodes with holder
	// And how to store matching result?
      }
    }
  }

  void Specialization::clear()
  {
    selected.clear();
  }
}