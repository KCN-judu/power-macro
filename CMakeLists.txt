cmake_minimum_required(VERSION 3.5.0)
project(PowerMacro VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

file(GLOB PowerMacro_SRC "Src/*.cpp")

add_executable(PowerMacro main.cpp ${PowerMacro_SRC})

target_include_directories(PowerMacro PUBLIC Inc)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)


