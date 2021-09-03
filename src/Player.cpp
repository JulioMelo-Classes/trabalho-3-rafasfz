#include <iostream>
#include <vector>
#include <queue>
#include <Player.h>
#include <chrono> //por causa do sleep
#include <thread> //por causa do sleep

std::vector<std::pair<char, std::pair<int, int>>> walk(std::vector<std::pair<char, std::pair<int, int>>> body, char new_direction_param) {
  char old_direction;

  for(int i = 0; i < body.size(); i++) {
    char new_direction;
    if(i == 0) {
      old_direction = body[i].first;
      body[i].first = new_direction_param;
      new_direction = new_direction_param;
    } else {
      char tmp = body[i].first;
      body[i].first = old_direction;
      new_direction = old_direction;
      old_direction = tmp;
    }

    char newRow, newCollumn;

    if(new_direction == 'N') {
      newRow = body[i].second.first - 1;
      newCollumn = body[i].second.second;
    } else if (new_direction == 'S') {
      newRow = body[i].second.first + 1;
      newCollumn = body[i].second.second;
    } else if (new_direction == 'L') {
      newRow = body[i].second.first;
      newCollumn = body[i].second.second + 1;
    } else if (new_direction == 'O') {
      newRow = body[i].second.first;
      newCollumn = body[i].second.second - 1;
    }

    body[i].second.first = newRow;
    body[i].second.second = newCollumn;

  }

  return body;
}

bool find_end(std::vector<std::pair<char, std::pair<int, int>>> snake_body, std::vector<std::string>map, std::vector<char> path) {
  char snake_direction = snake_body[0].first;
  int snake_row = snake_body[0].second.first;
  int snake_column = snake_body[0].second.second;

  for (char d : path) {

    if(d == 'N') {
      snake_row--;
    }
    if(d == 'S') {
      snake_row++;
    }
    if(d == 'O') {
      snake_column--;
    }
    if(d == 'L') {
      snake_column++;
    }
  }

  if(map[snake_row][snake_column] == '+')
    return true;

  return false;
}

bool is_safe(std::vector<std::pair<char, std::pair<int, int>>> snake_body, std::vector<std::string>map, std::vector<char> path, std::pair<int, int> *final_path_coordenate) {
  char snake_direction = snake_body[0].first;
  int snake_row = snake_body[0].second.first;
  int snake_column = snake_body[0].second.second;

  char old_direction = snake_direction;

  std::vector<std::pair<int, int>> old_coordenate;
  old_coordenate.push_back(std::make_pair(snake_row, snake_column));

  for (char d : path) {
    if(old_direction == 'N' && d == 'S') return false;
    if(old_direction == 'S' && d == 'N') return false;
    if(old_direction == 'O' && d == 'L') return false;
    if(old_direction == 'L' && d == 'O') return false;

    if(d == 'N') {
      snake_row--;
    }
    if(d == 'S') {
      snake_row++;
    }
    if(d == 'O') {
      snake_column--;
    }
    if(d == 'L') {
      snake_column++;
    }

    if(snake_row >= map.size() || snake_row < 0 || snake_column >= map[0].size() || snake_column < 0) {
      return false;
    }

    if(map[snake_row][snake_column] == '#'){
      return false;
    }

    for(auto coordenate : old_coordenate) {
      if(coordenate == std::make_pair(snake_row, snake_column)) {
        return false;
      }
    }

    old_coordenate.push_back(std::make_pair(snake_row, snake_column));

    old_direction = d;
  }

  *final_path_coordenate = std::make_pair(snake_row, snake_column);

  return true;
}

bool Player::find_solution(std::vector<std::string> map, std::vector<std::pair<char, std::pair<int, int>>> snake_body) {
  if(this->moves.size() > 0)
    return true;
  
  // std::cout << "Travou???" << std::endl;

  char snake_direction = snake_body[0].first;
  int snake_row = snake_body[0].second.first;
  int snake_column = snake_body[0].second.second;

  std::pair<int, int> final_path_coordenate;
  std::vector<std::pair<int, int>> finals_paths_coordenates;

  std::queue<std::vector<char>> possibles_paths;
  possibles_paths.push({});
  std::vector<char> path;

  while(!find_end(snake_body, map, path)) {
    // for (auto ch : path)
    //   std::cout << ch;
    // std::cout << std::endl;
    if(possibles_paths.size() == 0) 
      break;
    path = possibles_paths.front();
    possibles_paths.pop();

    for(auto direction : {'N', 'L', 'O', 'S'}) {
      bool put = true;
      std::vector<char> new_path = path;
      new_path.push_back(direction);
      if(is_safe(snake_body, map, new_path, &final_path_coordenate)) {
        for(auto fp : finals_paths_coordenates) {
          if(final_path_coordenate == fp) {
            put = false;
          }
        }
        if(put) {
          possibles_paths.push(new_path);
          finals_paths_coordenates.push_back(final_path_coordenate);
        }
      }
    }

    if(path.size() > 1000) {
      break;
    }
  }
  // std::cout << "Travou!!" << std::endl;
  if(find_end(snake_body, map, path)) {
    this->moves = path;
    return true;
  }

  return false;
}

char Player::next_move() {
  char move = this->moves[0];

  auto remove = this->moves.begin();
  this->moves.erase(remove);

  return move;
}