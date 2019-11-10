cmake_minimum_required(VERSION 3.14)
project(FormalLanguagesPracticum)

set(CMAKE_CXX_STANDARD 17)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
enable_testing()
add_executable(Test tests.cpp)

add_test(Test ${PROJECT_SOURCE_DIR}/bin/testing)

add_executable(FormalLanguagesPracticum main.cpp)

add_subdirectory(AutomataLibrary)
set(EXTRA_LIBS ${EXTRA_LIBS} AutomataLibrary)
SET(CMAKE_INSTALL_RPATH "${PROJECT_SOURCE_DIR}/bin")


target_link_libraries(FormalLanguagesPracticum ${EXTRA_LIBS})
target_link_libraries(Test ${EXTRA_LIBS})
target_link_libraries(Test Threads::Threads ${GTEST_LIBRARIES} ${GMOCK_BOTH_LIBRARIES})


add_definitions(-fprofile-arcs -ftest-coverage)
target_link_libraries(Test -fprofile-arcs)