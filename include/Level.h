#ifndef Level_h
#define Level_h
#include <iostream>
#include <vector>
#include "Snake.h"
#include "Player.h"

class Level {
  private:
    int rows;
    int columns;
    int foods;
    int foodsMax;
    int lifes;
    int initalRow;
    int initalColumn;
    int score = 0;
    int steps = 0;
    std::string game_mode;
    std::vector<std::string> map;
    Snake snake;
    Player p;

  public:
    Level(int rows, int columns, int foods, std::vector<std::string> map, std::string game_mode);

    int get_rows();
    int get_columns();
    int get_foods();
    void snake_eat();
    bool get_finished();
    void render();
    void snake_walk(char direction);
    void generate_food();
    bool verify_collapse();
    void reset();
    int get_lifes();
    bool verify_win();
    void IAMode();

};

#endif // Level_h