#include "Snake.h"
#include "Player.h"
#include <iostream>
#include <vector>
#include <chrono> //por causa do sleep
#include <thread> //por causa do sleep

Snake::Snake(char direction, int row, int column) {
  this->body.push_back(std::make_pair(direction, std::make_pair(row, column)));
}

Snake::Snake() {
  
}

int Snake::get_body_size() {
  return this->body.size();
}

void Snake::eat() {
  std::pair<char, std::pair<int, int>> lastPiece = this->body[this->body.size() - 1];
  char newPieceDirection = lastPiece.first;
  int newPieceRow, newPieceColumn;

  if(newPieceDirection == 'N') {
    newPieceRow = lastPiece.second.first + 1;
    newPieceColumn = lastPiece.second.second;
  } else if (newPieceDirection == 'S') {
    newPieceRow = lastPiece.second.first - 1;
    newPieceColumn = lastPiece.second.second;
  } else if (newPieceDirection == 'L') {
    newPieceRow = lastPiece.second.first;
    newPieceColumn = lastPiece.second.second - 1;
  } else if (newPieceDirection == 'O') {
    newPieceRow = lastPiece.second.first;
    newPieceColumn = lastPiece.second.second + 1;
  }

  std::pair<char, std::pair<int, int>> newPeace = std::make_pair(newPieceDirection, std::make_pair(newPieceRow, newPieceColumn));
  this->body.push_back(newPeace);
}

void Snake::walk(char new_direction_param) {
  char old_direction;

  for(int i = 0; i < this->body.size(); i++) {
    char new_direction;
    if(i == 0) {
      old_direction = this->body[i].first;
      this->body[i].first = new_direction_param;
      new_direction = new_direction_param;
    } else {
      char tmp = this->body[i].first;
      this->body[i].first = old_direction;
      new_direction = old_direction;
      old_direction = tmp;
    }

    char newRow, newCollumn;

    if(new_direction == 'N') {
      newRow = this->body[i].second.first - 1;
      newCollumn = this->body[i].second.second;
    } else if (new_direction == 'S') {
      newRow = this->body[i].second.first + 1;
      newCollumn = this->body[i].second.second;
    } else if (new_direction == 'L') {
      newRow = this->body[i].second.first;
      newCollumn = this->body[i].second.second + 1;
    } else if (new_direction == 'O') {
      newRow = this->body[i].second.first;
      newCollumn = this->body[i].second.second - 1;
    }

    this->body[i].second.first = newRow;
    this->body[i].second.second = newCollumn;

  }
}

void Snake::render_map(std::vector<std::string> map, int foods_left, int lifes, int score) {
  for(int i = 0; i < this->body.size(); i++) {
    if(i == 0) {
      map[this->body[i].second.first][this->body[i].second.second] = this->snake_head;
    } else {
      map[this->body[i].second.first][this->body[i].second.second] = this->snake_body;
    }
  }
  std::cout << "Vidas: " << lifes<< std::endl;
  std::cout << "Comidas restantes: " << foods_left << std::endl;
  std::cout << "Score: " << score << std::endl;
  for(auto line : map) {
    std::cout << line << std::endl;
  }
}

bool Snake::snake_point(int row, int collumn) {
  for (auto body_part : body) {
    if(body_part.second.first == row && body_part.second.second == collumn) {
      return true;
    }
  }

  return false;
}

bool Snake::verify_eat(std::vector<std::string> map, std::string game_mode) {
  int row = this->body[0].second.first;
  int column = this->body[0].second.second;

  if(map[row][column] == '+') {
    if(game_mode == "snake")
      this->eat();
    return true;
  }

  return false;
}

bool Snake::verify_collapse(std::vector<std::string> map) {
  int row = this->body[0].second.first;
  int column = this->body[0].second.second;

  for(int i = 0; i < this->body.size(); i++) {
    if(!(i == 0)) {
      map[this->body[i].second.first][this->body[i].second.second] = this->snake_body;
    }
  }

  if(map[row][column] == '#' || map[row][column] == 'O') {
    std::cout << map[row][column] << std::endl;
    std::cout << "Você colidiu nas seguintes coordenadas: " << std::endl;
    std::cout << "linha " << row << " coluna: " << column << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(10000));
    return true;
  }

  return false;
}

char Snake::IAMode(std::vector<std::string> map) {
  if(this->p.find_solution(map, this->body)) {
    return this->p.next_move();
  }

  if(this->body[0].first == 'S')
    return 'S';

  return 'N';
}
