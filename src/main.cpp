#include <torch/torch.h>
#include <iostream>
#include <pybind11/pybind11.h>
#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)


namespace py = pybind11;

int rand_tensor(int a, int b, int c) {
    torch::Tensor tensor = torch::rand({a, b, c}); 
    std::cout << tensor << std::endl;
    std::cout << "Hello Tensor" << std::endl;
}

PYBIND11_MODULE(_core, m) {
    m.doc() = R"pbdoc(
        Pybind11 with LibTorch
        -----------------------

        .. currentmodule:: libtorch_pybind

        .. autosummary::
           :toctree: _generate

           rand_tensor
    )pbdoc";

    m.def("rand_tensor", &rand_tensor, R"pbdoc(
        Print a random tensor
    )pbdoc");

#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}
