#include "Level.h"
#include "Snake.h"
#include "Player.h"
#include <iostream>
#include <vector>
#include <ctime>

Level::Level(int rows, int columns, int foods, std::vector<std::string> map, std::string game_mode) {
  this->rows = rows;
  this->columns = columns;
  this->foods = foods;
  this->foodsMax = foods;
  this->map = map;
  this->lifes = 5;
  this->game_mode = game_mode;

  for(int i = 0; i < this->map.size(); i++) {
    for(int j = 0; j < this->map[i].size(); j++) {
      if(this->map[i][j] == '*') {
        this->map[i][j] = ' ';
        Snake snake('N', i, j);
        this->snake = snake;
        this->initalRow = i;
        this->initalColumn = j;
      }
    }
  }

  this->generate_food();
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

void Level::render() {
  this->snake.render_map(this->map, this->foods, this->lifes);
}

void Level::snake_walk(char direction) {
  this->snake.walk(direction);
  if(this->snake.verify_eat(this->map, this->game_mode)) {
    this->foods--;
    this->generate_food();
  }
}

void Level::generate_food() {
  std::vector<std::pair<int, int>> points;
  for(int i = 0; i < this->map.size(); i++) {
    for(int j = 0; j < this->map[i].size(); j++) {
      if(this->map[i][j] == '+') {
        this->map[i][j] = ' ';
      }
      if(this->map[i][j] == ' ' && !this->snake.snake_point(i, j)) {
        points.push_back(std::make_pair(i , j));
      }
    }
  }

  srand((unsigned) time(0));
  std::pair<int, int> random_point = points[rand() % points.size()];
  this->map[random_point.first][random_point.second] = '+';
}

bool Level::verify_collapse() {
  return this->snake.verify_collapse(this->map);
}

void Level::reset() {
  this->lifes--;
  this->foods = this->foodsMax;
  Snake snake('N', initalRow, initalColumn);
  this->snake = snake;
  this->generate_food();
}

int Level::get_lifes() {
  return this->lifes;
}

bool Level::verify_win() {
  if(this->foods == 0)
    return true;
  return false;
}

void Level::IAMode() {
  this->snake_walk(this->snake.IAMode(this->map));
}

