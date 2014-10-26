#include <iostream>

#include "../assembly/assembly.hpp"

#include "../node/module.hpp"
#include "../node/function.hpp"
#include "../node/select.hpp"


using namespace std;

int main()
{
  hlcg::Assembly *ass = new hlcg::Assembly();
  
  hlcg::Module *mod = new hlcg::Module(ass, L"my.module");
  ass->modules.push_back(mod);
  
  // hlcg::Function *fun = new hlcg::Function(L"fun", fun_type);
  ass->build();
  ass->clear();
  
  //
  // Global and Member selector tests
  //
  hlcg::Member *mem = new hlcg::Member(ass, new hlcg::Global(ass), L"Int32");
  mem->build();
  cout << mem->get_selected().size() << endl;
  cout << dynamic_cast<hlcg::Selector *>(mem->place)->get_selected().size() << endl;
  
  delete ass;
  delete mod;
}