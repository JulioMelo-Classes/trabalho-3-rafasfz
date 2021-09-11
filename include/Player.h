#ifndef Player_h
#define Player_h

#include <iostream>
#include <vector>

class Player {
  public:
    /*! retorna qual próximo passo a cobra tem que dar para chegar a comida
    @return um char com a direção pra onde a cobra tem que ir pra chegar a comida
		*/
    char next_move();

    /*! encontra uma solução pra a cobra chegar até a comida e armazena no vetor moves
    @param map o mapa o qual tera os obstaculos e a comida
    @param snake_body o corpo da cobra contendo sua posição e a direção pra qual esta seguindo
    @return true caso encontrado uma solução e false caso o contrario
		*/
    bool find_solution(std::vector<std::string> map, std::vector<std::pair<char, std::pair<int, int>>> snak_body);
  
  private:
    std::vector<char> moves; // vetor de direções que a cobra tem que seguir
  
};

#endif