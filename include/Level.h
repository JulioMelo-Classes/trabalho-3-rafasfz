#ifndef Level_h
#define Level_h
#include <iostream>
#include <vector>

class Level {
  private:
    int rows;
    int columns;
    int foods;
    std::vector<std::string> map;

  private:
    Level(int rows, int columns, int foods, std::vector<std::string> map);

    int get_rows();
    int get_columns();
    int get_foods();
    void snake_eat();
    bool get_finished();

};

#endif // Level_h