/*
 * Signals utility
 * 
 */

#pragma once

#include "signals.hpp"

namespace hlcg
{
  template<typename R, typename... Args>
  Signal<R(Args...)>::~Signal()
  {
    for(auto callee : callees)
      erase(*callee);
  }
  
  template<typename R, typename... Args>
  std::map<Slot<R(Args...)>*, R> Signal<R(Args...)>::call(Args... args)
  {
    std::map<Slot<R(Args...)>*, R> ret;
    ret.reserve(callees.size());
    for(auto callee : callees)
    {
      ret[callee] = callee->call(args...);
    }
    return ret;
  }
  
  template<typename R, typename... Args>
  std::map<Slot<R(Args...)>*, R> Signal<R(Args...)>::operator() (Args... args)
  {
    return this->call(args...);
  }
  
  // SLOTS MANAGEMENT HERE
  
  template<typename R, typename... Args>
  void Signal<R(Args...)>::insert(Slot<R(Args...)> &s)
  {
    callees.insert(&s);
    s.callers.insert(this);
  }
  
  template<typename R, typename... Args>
  void Signal<R(Args...)>::erase(Slot<R(Args...)> &s)
  {
    callees.erase(&s);
    s.callers.erase(this);
  }
  
  template<typename R, typename... Args>
  Slot<R(Args...)>::~Slot()
  {
    for(auto caller : callers)
      caller->erase(*this);
  }
  
  template<typename R, typename... Args>
  R Slot<R(Args...)>::call(Args... args) const
  {
    return func(args...);
  }
  
  ///////////////////////////////////////////////////////////////////////
  
  template<typename... Args>
  Signal<void(Args...)>::~Signal()
  {
    for(auto callee : callees)
      erase(*callee);
  }
  
  template<typename... Args>
  void Signal<void(Args...)>::call(Args... args)
  {
    for(auto callee : callees)
    {
      callee->call(args...);
    }
  }
  
  template<typename... Args>
  void Signal<void(Args...)>::operator() (Args... args)
  {
    return this->call(args...);
  }
  
  // SLOTS MANAGEMENT HERE
  
  template<typename... Args>
  void Signal<void(Args...)>::insert(Slot<void(Args...)> &s)
  {
    callees.insert(&s);
    s.callers.insert(this);
  }
  
  template<typename... Args>
  void Signal<void(Args...)>::erase(Slot<void(Args...)> &s)
  {
    callees.erase(&s);
    s.callers.erase(this);
  }
  
  template<typename... Args>
  Slot<void(Args...)>::~Slot()
  {
    for(auto caller : callers)
      caller->erase(*this);
  }
  
  template<typename... Args>
  void Slot<void(Args...)>::call(Args... args) const
  {
    return func(args...);
  }
}
