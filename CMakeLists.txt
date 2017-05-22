cmake_minimum_required(VERSION 2.8)

project(arptool)

# Use C++14
set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra -stdlib=libc++")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")

# Compile and link
file(GLOB SRC "*.h" "*.cpp")
add_executable(arptool ${SRC})
