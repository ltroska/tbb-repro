#include "foo_interface.h"

#include <iostream>

struct Foo : FooInterface {
    Foo(bool access_ets) { if(access_ets) const auto value = this->ets.local(); }
    void do_something(int i) override { this->ets.local() = i;}
};

extern "C" FooInterface* create_object(bool access)
{
  return new Foo(access);
}

extern "C" void destroy_object(FooInterface* object)
{
  delete object;
}
