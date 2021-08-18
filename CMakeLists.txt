cmake_minimum_required(VERSION 3.5)

project(snaze)

include_directories( include )

add_executable( snaze
  src/Snaze.cpp
  src/SnakeGame.cpp
)