cmake_minimum_required(VERSION 3.27)
project(QIT_Analysis_Of_Lanqiao)

set(CMAKE_CXX_STANDARD 20)

add_executable(008 topics/008/largest_rectangle_area_stack.cpp)
add_executable(008_dp topics/008/largest_rectangle_area_dp.cpp)
add_executable(010 topics/010/reverse_linked_list.cpp)
add_executable(010_simple topics/010/reverse_linked_list_simple.cpp)