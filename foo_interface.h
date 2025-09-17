#include <oneapi/tbb.h>
#include <oneapi/tbb/enumerable_thread_specific.h>

#include <dlfcn.h>

#include <iostream>


struct FooInterface {
    virtual ~FooInterface() { std::cout << "destroying FooInterface from thread "<<  tbb::this_task_arena::current_thread_index() << std::endl; }
    virtual void do_something(int i) = 0;
protected:
    oneapi::tbb::enumerable_thread_specific<double> ets;
};

inline auto load_foo(const char* path, bool access_ets) {
    void* handle = dlopen(path, RTLD_LAZY);
    auto create = (FooInterface* (*)(bool))dlsym(handle, "create_object");
    auto destroy = (void (*)(FooInterface*))dlsym(handle, "destroy_object");

    FooInterface* foo = (FooInterface*)create(access_ets);

    return std::shared_ptr<FooInterface>(foo, [destroy](FooInterface* object)  {
        destroy(object);
    });
}

inline void run_algorithm_using_foo(std::shared_ptr<FooInterface> foo) {
    oneapi::tbb::parallel_for(oneapi::tbb::blocked_range<int>(0, 50), [&](const auto r) { 
        for(int i=r.begin(); i!=r.end(); ++i) foo->do_something(i);
    });
}

inline void run_algorithm() {
    oneapi::tbb::parallel_for(oneapi::tbb::blocked_range<int>(0, 1), [&](const auto) { 
        
    });
}
