#include <iostream>

#include "../assembly/assembly.hpp"

#include "../node/module.hpp"
#include "../node/function.hpp"
#include "../node/select.hpp"


using namespace std;

int main()
{
  hlcg::Module *mod = new hlcg::Module(L"my.module");
  // hlcg::Function *fun = new hlcg::Function(L"fun", fun_type);
  
  hlcg::Assembly *ass = new hlcg::Assembly();
  ass->modules.push_back(mod);
  
  auto bld = ass->build();
  ass->clear();
  
  //
  // Global and Member selector tests
  //
  hlcg::Member *mem = new hlcg::Member(new hlcg::Global(), L"Int32");
  mem->build(bld);
  cout << mem->get_selected().size() << endl;
  
  delete ass;
  delete mod;
}