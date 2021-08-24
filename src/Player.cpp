#include <iostream>
#include <vector>
#include <Player.h>

bool Player::find_solution(std::vector<std::string> map, std::vector<std::pair<char, std::pair<int, int>>> snake_body) {
  if(this->moves.size() > 0)
    return true;
  
  char snake_direction = snake_body[0].first;
  int snake_row = snake_body[0].second.first;
  int snake_column = snake_body[0].second.second;
  
  if(snake_direction == 'N') {
    if(map[snake_row-1][snake_column] == ' ' || map[snake_row-1][snake_column] == '+') {
      this->moves.push_back('N');
      return true;
    }
    if(map[snake_row][snake_column+1] == ' ' || map[snake_row][snake_column+1] == '+') {
      this->moves.push_back('L');
      return true;
    }
    if(map[snake_row][snake_column-1] == ' ' || map[snake_row][snake_column-1] == '+') {
      this->moves.push_back('O');
      return true;
    }
  }

  if(snake_direction == 'S') {
    if(map[snake_row+1][snake_column] == ' ' || map[snake_row+1][snake_column] == '+') {
      this->moves.push_back('S');
      return true;
    }
    if(map[snake_row][snake_column+1] == ' ' || map[snake_row][snake_column+1] == '+') {
      this->moves.push_back('L');
      return true;
    }
    if(map[snake_row][snake_column-1] == ' ' || map[snake_row][snake_column-1] == '+') {
      this->moves.push_back('O');
      return true;
    }
  }

  if(snake_direction == 'L') {
    if(map[snake_row-1][snake_column] == ' ' || map[snake_row-1][snake_column] == '+') {
      this->moves.push_back('N');
      return true;
    }
    if(map[snake_row+1][snake_column] == ' ' || map[snake_row+1][snake_column] == '+') {
      this->moves.push_back('S');
      return true;
    }
    if(map[snake_row][snake_column+1] == ' ' || map[snake_row][snake_column+1] == '+') {
      this->moves.push_back('L');
      return true;
    }
  }

  if(snake_direction == 'O') {
    if(map[snake_row-1][snake_column] == ' ' || map[snake_row-1][snake_column] == '+') {
      this->moves.push_back('N');
      return true;
    }
    if(map[snake_row+1][snake_column] == ' ' || map[snake_row+1][snake_column] == '+') {
      this->moves.push_back('S');
      return true;
    }
    if(map[snake_row][snake_column-1] == ' ' || map[snake_row][snake_column-1] == '+') {
      this->moves.push_back('O');
      return true;
    }
  }

  return false;
}

char Player::next_move() {
  char move = this->moves[0];

  auto remove = this->moves.begin();
  this->moves.erase(remove);

  return move;
}