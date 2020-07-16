cmake_minimum_required(VERSION 3.0.0)
project(bfi VERSION 0.1.0)

include(CTest)
enable_testing()

if (MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

include_directories(include)

add_executable(bfi main.cpp "src/tape_machine.cpp")

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
