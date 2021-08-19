#include "Level.h"

Level::Level(int rows, int columns, int foods, std::vector<std::string> map) {
  this->rows = rows;
  this->columns = columns;
  this->foods = foods;
  this->map = map;
}

int Level::get_rows() {
  return this->rows;
}

int Level::get_columns() {
  return this->columns;
}

int Level::get_foods() {
  return this->foods;
}

void Level::snake_eat() {
  this->foods--;
}

bool Level::get_finished() {
  return this->foods == 0;
}

