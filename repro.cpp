#include <pybind11/pybind11.h>

#include "foo_interface.h"

PYBIND11_MODULE(repro, m) {
    pybind11::class_<FooInterface, std::shared_ptr<FooInterface>>(m, "FooInterface");

    m.def("Foo", &load_foo, pybind11::arg("path"), pybind11::arg("access_ets"));

    m.def("run_algorithm_using_foo", &run_algorithm_using_foo, pybind11::arg("foo"));
    m.def("run_algorithm", &run_algorithm);
}
