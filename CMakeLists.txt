cmake_minimum_required(VERSION 3.15...3.19)

project(libtorch_pybind VERSION "0.0.1")

# set an environment variable to where you unzipped libtorch
list(APPEND CMAKE_PREFIX_PATH "$ENV{TORCH_PATH}")
find_package(Torch REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")



if(SKBUILD)
  # Scikit-Build does not add your site-packages to the search path
  # automatically, so we need to add it _or_ the pybind11 specific directory
  # here.
  execute_process(
    COMMAND "${PYTHON_EXECUTABLE}" -c
            "import pybind11; print(pybind11.get_cmake_dir())"
    OUTPUT_VARIABLE _tmp_dir
    OUTPUT_STRIP_TRAILING_WHITESPACE COMMAND_ECHO STDOUT)
  list(APPEND CMAKE_PREFIX_PATH "${_tmp_dir}")
endif()

# Now we can find pybind11
find_package(pybind11 CONFIG REQUIRED)

pybind11_add_module(_core MODULE src/main.cpp)

target_link_libraries(_core PUBLIC "${TORCH_LIBRARIES}")
set_property(TARGET _core PROPERTY CXX_STANDARD 14)

target_compile_definitions(_core PRIVATE VERSION_INFO=${PROJECT_VERSION})

install(TARGETS _core DESTINATION .)
