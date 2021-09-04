#ifndef Level_h
#define Level_h
#include <iostream>
#include <vector>
#include "Snake.h"
#include "Player.h"

class Level {
  private:
    int rows; //<! quantidade de linhas do mapa
    int columns; //<! quantidade de colunas do mapa
    int foods; //<! quantidade de comidas já comidas pela cobra
    int foodsMax; //<! quantidade de comidas iniciais
    int lifes; //<! quantidade de vidas que a cobra possui
    int initalRow; //<! linha onde a cobra inicia
    int initalColumn; //<! coluna onde a cobra inicia
    int score = 0;  //<! score do jogo
    int steps = 0;  //<! passos que a cobra deu até a proxima comida
    std::string game_mode;  //<! modo de jogo "snake" ou "pacman"
    std::vector<std::string> map; //<! vetor de string contendo o mapa
    Snake snake; //<! a cobra que esta no jogo
    Player p;

  public:
    /*! Construtor da classe
    @param rows o numero de linhas do mapa
    @param columns o numero de colunas do mapa
    @param foods o numero de comidas no mapa
    @param map um vetor de stirng que será o mapa
    @param gamemode o modo de jogo "snake" ou "pacman"
		*/
    Level(int rows, int columns, int foods, std::vector<std::string> map, std::string game_mode);

    /*! pega o número de linhas do mapa
    @return o número de linhas do mapa
		*/
    int get_rows();

    /*! pega o número de colunas do mapa
    @return o número de colunas do mapa
		*/
    int get_columns();

    /*! pega o número de comidas que a cobra ja comeu
    @return o número de comidas que a cobra ja comeu
		*/
    int get_foods();

    /*! diminui em 1 a comida do mapa
		*/
    void snake_eat();

    /*! verifica se o jogo ja acabou e retorna true se sim e false caso o contrario
    @return um bool true caso o jogo já tenha terminado e um bool false caso o jogo ainda esteja acontecendo
		*/
    bool get_finished();

    /*! rendereiza o mapa do jogo
		*/
    void render();

    /*! faz a cobra andar para uma direção
    @param direction um char contendo um caracter para a nova direção que a cobra deve seguir
		*/
    void snake_walk(char direction);

    /*! gera comida em algum lugar aleatorio do mapa desde que ele seja vazio
		*/
    void generate_food();

    /*! verifica se a cobra bateu na parede do mapa ou nela mesmo
    @return um bool true caso a cobra tem batido em algum lugar e false caso o contrario
		*/
    bool verify_collapse();

    /*! reseta o mapa diminuindo em 1 a quantidade de vidas da cobra
		*/
    void reset();

    /*! pega a quantidade de vidas restantes que a cobra tem
    @return a quantidade de vidas restantes da cobra
		*/
    int get_lifes();

    /*! verifica se a cobra tenha vencido o jogo
    @return true caso a cobra venceu o jogo e false caso o contrario
		*/
    bool verify_win();

    /*! faz a cobra se controlar sozinho por meio de uma "IA"
		*/
    void IAMode();

};

#endif // Level_h