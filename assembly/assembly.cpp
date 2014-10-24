#include "assembly.hpp"

namespace hlcg {
  Build Assembly::build()
  {
    Build b;
    b.ass = this;
    b.ctx = new llvm::LLVMContext();
    b.mod = new llvm::Module("Module", *(b.ctx));
    return b;
  }

  void Assembly::clear()
  {

  }
}