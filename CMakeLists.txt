cmake_minimum_required(VERSION 3.20)
project(main)

find_package(spdlog REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

add_executable(${PROJECT_NAME} aaaa.cpp)
target_link_libraries(${PROJECT_NAME} OpenGL::OpenGL GLUT::GLUT spdlog::spdlog)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(tests test.cpp)
target_link_libraries(tests
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(tests)
