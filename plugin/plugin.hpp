#pragma once

#include <memory>


namespace hlcg
{ 
  class Plugin
  {
  private:
    // Loaded library pointer for unloading
    // when destructor invoked
    
  public:
    virtual ~Plugin();	// implement library unloading
    // can't copy plugin
    Plugin(const Plugin &orig) = delete;
    Plugin & operator= (const Plugin &orig) = delete;
    // but it is moovable
    Plugin(Plugin &&orig);
    Plugin & operator= (Plugin &&orig);
    
  public:
    // Plugin interface here
  };
}