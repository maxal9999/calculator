set (CMAKE_CXX_STANDARD 11)
cmake_minimum_required(VERSION 2.8)

set (PROJECT calculator)

project (${PROJECT})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -pthread")

include_directories(calculator)

#------------------------------------------------------------------

set (LIB_HEADERS calculator/calculator.hpp)

set (LIB_SOURCES calculator/calculator.cpp)

set (LIB ${PROJECT}_lib)

add_library (${LIB} ${LIB_HEADERS} ${LIB_SOURCES})

#------------------------------------------------------------------

set (SOURCES main.cpp)

add_executable (${PROJECT} ${SOURCES})

target_link_libraries (${PROJECT} ${CMAKE_THREAD_LIBS_INIT} ${LIB})

#------------------------------------------------------------------

#set (TESTS_SOURCES test/calculator_tests.cpp)
#
#set (TEST test_${PROJECT})
#add_executable (${TEST} ${TESTS_SOURCES})
#
#find_package (Boost COMPONENTS unit_test_framework REQUIRED)
#if(Boost_FOUND)
#   include_directories(${Boost_INCLUDE_DIRS})
#   target_link_libraries (${TEST} ${Boost_LIBRARIES} ${LIB})
#endif()
#
#enable_testing ()
#add_test (${TEST} ${TEST})
