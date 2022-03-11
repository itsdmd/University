# Download & Install CMake: certutil.exe -urlcache -split -f "https://github.com/Kitware/CMake/releases/download/v3.22.1/cmake-3.22.1-windows-x86_64.msi" cmake.msi  && msiexec /i "cmake.msi"
# Initiate with: cmake -S . -B build && cmake --build build && cd build && ctest & cd ..

cmake_minimum_required(VERSION 3.14)
project(my_project)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  test                        #
  test.cpp                    #
)

target_link_libraries(
  test
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(test)    #