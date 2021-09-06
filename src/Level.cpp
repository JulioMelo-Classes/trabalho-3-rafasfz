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
  bool random_snake_initial_position = true;

  for(int i = 0; i < this->map.size(); i++) {
    for(int j = 0; j < this->map[i].size(); j++) {
      if(this->map[i][j] == '*') {
        this->map[i][j] = ' ';
        Snake snake('N', i, j);
        this->snake = snake;
        this->initalRow = i;
        this->initalColumn = j;
        random_snake_initial_position = false;
      }
    }
  }

  if(random_snake_initial_position) {
    std::vector<std::pair<int, int>> free_positions;
    for(int i = 0; i < this->map.size(); i++) {
      for(int j = 0; j < this->map[i].size(); j++) {
        if(this->map[i][j] == ' ') {
          free_positions.push_back(std::make_pair(i, j));
        }
      }
    }

    bool snake_in_game = false;
    std::pair<int, int> initial_snake_position;

    while(!snake_in_game) {
      srand((unsigned) time(0));
      initial_snake_position = free_positions[rand() % free_positions.size()];

      int sorted_row = initial_snake_position.first;
      int sorted_column = initial_snake_position.second;

      if(this->map[sorted_row - 1][sorted_column] == ' ' || this->map[sorted_row][sorted_column-1] == ' ' || this->map[sorted_row][sorted_column + 1] == ' ') {
        snake_in_game = true;
        Snake snake('N', sorted_row, sorted_column);
        this->snake = snake;
        this->initalRow = sorted_row;
        this->initalColumn = sorted_column;
      } else if(this->map[sorted_row + 1][sorted_column] == ' ') {
        snake_in_game = true;
        Snake snake('S', sorted_row, sorted_column);
        this->snake = snake;
        this->initalRow = sorted_row;
        this->initalColumn = sorted_column;
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
  this->snake.render_map(this->map, this->foods, this->lifes, this->score);
}

void Level::snake_walk(char direction) {
  this->snake.walk(direction);
  if(this->snake.verify_eat(this->map, this->game_mode)) {
    this->score = this->steps > 20 ? this->score + 100 : this->score + (((20 - this->steps) * 10) + 100);
    this->steps = 0;
    this->foods--;
    this->generate_food();
  }
  this->steps++;
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

void Level::reset(bool loose_life) {
  if(loose_life)
    this->lifes--;
  else
    this->lifes = 5;
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

