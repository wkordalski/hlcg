#pragma once

#include "plugin.hpp"

#include <memory>
#include <string>
#include <vector>

namespace hlcg
{
  // Is not thread-safe
  // If neaded, add mutex to allow others access
  class PluginManager
  {
  protected:
    PluginManager();
    ~PluginManager();
    
    PluginManager(const PluginManager &orig) = delete;
    PluginManager(PluginManager &&orig) = delete;
    PluginManager & operator=(const PluginManager &orig) = delete;
    PluginManager & operator=(PluginManager &&orig) = delete;
    
  public:
    static PluginManager & instance();
    
    std::shared_ptr<Plugin> attach(std::string file);
    void detach(std::shared_ptr<Plugin> plugin);
    
    // Removes all unused
    void clear();
    
    // TODO: how to stay usable plugins loaded for the next part of translation?
  };
}