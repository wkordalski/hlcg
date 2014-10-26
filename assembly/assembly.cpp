#include "assembly.hpp"

namespace hlcg {
  Assembly::Assembly()
  {
    ctx = new llvm::LLVMContext();
    mod = new llvm::Module("hlcgModule", *(ctx));
  }
  
  void Assembly::build()
  {
  }

  void Assembly::clear()
  {

  }
}