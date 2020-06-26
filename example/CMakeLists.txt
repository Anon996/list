CMAKE_MINIMUM_REQUIRED(VERSION 2.8)  
project (example)

set(SRC example.c)

include_directories(../)
link_directories(../../build)

add_executable(example ${SRC})

target_link_libraries(example libdulist.a)

