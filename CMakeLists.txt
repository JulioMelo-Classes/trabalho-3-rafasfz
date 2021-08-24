cmake_minimum_required(VERSION 3.5)

set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
set (CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")

project(snaze)

include_directories( include )

add_executable( snaze
  src/Snaze.cpp
  src/SnakeGame.cpp
  src/Level.cpp
  src/Snake.cpp
  src/Player.cpp
)