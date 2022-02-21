import sys

try:
    from skbuild import setup
except ImportError:
    print(
        "Please update pip, you need pip 10 or greater,\n"
        " or you need to install the PEP 518 requirements in pyproject.toml yourself",
        file=sys.stderr,
    )
    raise

from setuptools import find_packages

setup(
    name="libtorch_pybind",
    version="0.0.1",
    description="a minimal example package for libtorch w/ pybind11)",
    author="lazyoracle",
    license="MIT",
    packages=find_packages(where="src"),
    package_dir={"": "src"},
    cmake_install_dir="src/libtorch_pybind",
    include_package_data=True,
    extras_require={"test": ["pytest"]},
    python_requires=">=3.8",
)
