cmake_minimum_required(VERSION 3.0.0)
project(bfi VERSION 0.1.0)

include(CTest)
enable_testing()

include_directories(include)

if (MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

add_executable(bfi main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
