cmake_minimum_required(VERSION 3.15)
project(DemoVersionOfNumber)

#set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -c")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH "/usr/share/SFML/cmake/Modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2.4.2 COMPONENTS graphics audio REQUIRED)


add_executable(DemoVersionOfNumber main.cpp DemoVersionOfNumber.h Sorts.h)

target_link_libraries(DemoVersionOfNumber sfml-graphics sfml-window sfml-system)