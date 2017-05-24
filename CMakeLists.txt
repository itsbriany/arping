cmake_minimum_required(VERSION 2.8)

project(arptool)

# Use C++14
set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra -stdlib=libc++")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")

# Compile and link for your platform
file(GLOB SRC "*.h" "*.cpp")
file(GLOB LINUX_SRC "linux_*.h" "linux_*.cpp")
file(GLOB MACOS_SRC "macos_*.h" "macos_*.cpp")

# Remove the sources incompatible with your platform
if (UNIX AND APPLE)
  list(REMOVE_ITEM SRC ${LINUX_SRC})
elseif(UNIX)
  list(REMOVE_ITEM SRC ${MACOS_SRC})
endif()

add_executable(arptool ${SRC})
