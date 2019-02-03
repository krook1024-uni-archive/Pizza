# Minimum CMake 3.0
cmake_minimum_required(VERSION 3.0)

# HunterGate is a package manager for CMake
include("cmake/HunterGate.cmake")
HunterGate(
  URL "https://github.com/ruslo/hunter/archive/v0.19.32.tar.gz"
  SHA1 "a6ed6615c08e37b929b134f8c8e2e7392eb63f13")

# Project name is defined here
project(pizza)

# Let hunter find gflags for us
hunter_add_package(gflags)
find_package(gflags CONFIG REQUIRED)

# Source files for `pizza` are currently `Main.cpp and `Pizza.cpp`
add_executable(pizza Main.cpp Pizza.cpp)

# We need to link gflags to our executable
target_link_libraries(pizza
	gflags)

# Put binary to bin/
