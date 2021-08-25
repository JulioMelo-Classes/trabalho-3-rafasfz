#ifndef Snake_h
#define Snake_h
#include <iostream>
#include <vector>
#include <Player.h>

class Snake {
  private:
    std::vector<std::pair<char, std::pair<int, int>>> body;
    char snake_head = 'v';
    char snake_body = 'O';
    Player p;

  public:
    Snake(char direction, int row, int column);
    Snake();
    int get_body_size();
    void eat();
    void walk(char new_direction);
    void render_map(std::vector<std::string> map, int foods_left, int lifes, int score);
    bool snake_point(int row, int column);
    bool verify_eat(std::vector<std::string> map, std::string game_mode);
    bool verify_collapse(std::vector<std::string> map);
    char IAMode(std::vector<std::string> map);
};

#endif