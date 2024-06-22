# CMakeLists
#
# Copyright 2024 KoreLib Developers. All Rights Reserved.
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the â€œSoftwareâ€), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED AS IS, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES
# OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

cmake_minimum_required(VERSION 3.11)
project(kore)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

FetchContent_Declare(fmt GIT_REPOSITORY https://github.com/fmtlib/fmt.git GIT_TAG 10.2.1)
FetchContent_Declare(backward GIT_REPOSITORY https://github.com/bombela/backward-cpp GIT_TAG v1.6)

FetchContent_MakeAvailable(fmt)
FetchContent_MakeAvailable(backward)

option(KORE_SHARED "Build dynamic Kore shared library" OFF)
option(KORE_ENABLE_ASSERTIONS "Enable assertions" ON)

if(KORE_SHARED)
    set(KORE_LIB_TYPE SHARED)
else()
    set(KORE_LIB_TYPE STATIC)
endif()

if (KORE_ENABLE_ASSERTIONS)
    add_compile_definitions(
        KORE_ENABLE_ASSERTIONS
    )
endif()

add_library(kore ${KORE_LIB_TYPE}
    include/Exceptions/RuntimeException.hpp
    source/Exceptions/RuntimeException.cpp
)

target_include_directories(kore PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(kore PUBLIC
    fmt
    backward
)
