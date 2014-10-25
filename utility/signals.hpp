#pragma once

#include <functional>
#include <map>
#include <set>

namespace hlcg
{
  template<typename T>
  class Signal;
  
  template<typename T>
  class Slot;
  
  template<typename R, typename... Args>
  class Signal<R(Args...)>
  {
    std::set<Slot<R(Args...)>*> callees;
  public:
    virtual ~Signal();
    
    std::map<Slot<R(Args...)>*, R> call(Args... args);
    std::map<Slot<R(Args...)>*, R> operator() (Args... args);
    
    // SLOTS MANAGEMENT HERE
    
    void insert(Slot<R(Args...)> &s);
    void erase(Slot<R(Args...)> &s);
    
    // TODO: some iteration
  };
  
  template<typename R, typename... Args>
  class Slot<R(Args...)>
  {
    std::function<R(Args...)> func;
    std::set<Signal<R(Args...)>*> callers;
    
  public:
    Slot(std::function<R(Args...)> f) : func(f) {}
    virtual ~Slot();
    
    R call(Args... args) const;
    
    friend class Signal<R(Args...)>;
  };
  
  template<typename... Args>
  class Signal<void(Args...)>
  {
    std::set<Slot<void(Args...)>*> callees;
  public:
    virtual ~Signal();
    
    void call(Args... args);
    void operator() (Args... args);
    
    // SLOTS MANAGEMENT HERE
    
    void insert(Slot<void(Args...)> &s);
    void erase(Slot<void(Args...)> &s);
    
    // TODO: some iteration
  };
  
  template<typename... Args>
  class Slot<void(Args...)>
  {
    std::function<void(Args...)> func;
    std::set<Signal<void(Args...)>*> callers;
    
  public:
    Slot(std::function<void(Args...)> f) : func(f) {}
    virtual ~Slot();
    
    void call(Args... args) const;
    
    friend class Signal<void(Args...)>;
  };
}

#include "signals.hxx"
