#ifndef Player_h
#define Player_h

#include <iostream>
#include <vector>

class Player {
  public:
    char next_move();
    bool find_solution(std::vector<std::string> map, std::vector<std::pair<char, std::pair<int, int>>> snak_body);
  
  private:
    std::vector<char> moves;
    std::vector<std::pair<int, int>> tested_coordenates;
  
};

#endif