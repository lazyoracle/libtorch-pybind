# libtorch-pybind

This is an example repository showing how to build libraries using the `torch` C++ frontend (aka `libtorch`) and then provide a high-level Python interface through `pybind11`. 

## What this is not - 

- Standalone implementations with `libtorch` C++ frontend (check [here](https://pytorch.org/cppdocs/frontend.html#the-c-frontend))
- Torchscipt JIT versions of `PyTorch` models (check [here](https://pytorch.org/docs/stable/jit.html))
- C++ extensions for `PyTorch`(check [here](https://pytorch.org/tutorials/advanced/cpp_extension.html))

## What this is - 

We list below the scenario(s) that might motivate you to build a solution like this. It is likely that you only need this when all (or most) of these requirments are present.

- You wish to use the rich `torch` ecosystem of tape-based Automatic Differentiation and Deep Learning workflows
- You wish to build production level code with high performance and latency requirements
- Your code doesn't run in the cloud but runs on the customer's system
- You wish to obfuscate source code and provide pre-compiled binaries to your customer
- Your customer plans to use Python as a high-level language to interface with your SDK

## Installation

### libtorch

Get precompiled dynamically linked binaries from [here](https://pytorch.org/get-started/locally/#start-locally). These get unzipped to `libtorch/`. Thereafter, the `libtorch/lib/*.so*` must be copied over to your system shared library location (typically `/usr/lib/`).

### build tools

You will need `cmake`, `scikit-build`, `pybind11` and a recent C++ compiler.

### library installation

```bash
git clone https://github.com/lazyoracle/libtorch-pybind
cd libtorch-pybind
pip install .
```

This will compile and link the C++ code, create the extensions and bindings and install the package to your python environment. We recommend using a virtual environment. You can test it with the following:

```python
python -c "from libtorch_pybind import rand_tensor as rndt; print(rndt(1, 2, 3))"
```

### wheels

To build pre-compiled wheels for distribution, use the following command from the root of the repository after setting up the build toolchain and dependencies:

```bash
python -m pip wheel -w build/ .
```

You will find a `.whl` file in your `build/` directory which can then be used for standalone installations using `pip install libtorch_pybind-0.0.1-cp39-cp39-linux_x86_64.whl`. Note that this is python version, OS and arch specific. Consider using `manylinux` and `cibuildwheel`.
