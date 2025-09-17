#include "foo_interface.h"

int main() {
    auto foo = load_foo("libfoo.so", true);
    run_algorithm_using_foo(foo);

    return 0;
}
