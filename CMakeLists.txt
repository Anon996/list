CMAKE_MINIMUM_REQUIRED(VERSION 2.8)  

set(SRC du_list.c)
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_C_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
set(CMAKE_C_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

add_library(dulist STATIC ${SRC})  

