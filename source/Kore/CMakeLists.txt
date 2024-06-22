add_library(kore ${KORE_LIB_TYPE}
    include/Assertion.hpp
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
