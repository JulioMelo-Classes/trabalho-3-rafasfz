#ifndef Snake_h
#define Snake_h
#include <iostream>
#include <vector>
#include <Player.h>

class Snake {
  private:
    std::vector<std::pair<char, std::pair<int, int>>> body; //<! vetor de um par contendo a direção da cobra e sua posição no mapa
    char snake_head = 'v'; // Caracter que representa a cabeça da cobra na renderezição
    char snake_body = 'O'; // Caracter que representa o corpo da cobra na renderezição
    Player p; // Player que controla a cobra

  public:
    /*! Contrutor da classe Snake
    @param direction direção inicial da cobra
    @param row linha inicial da cobra
    @param column coluna inicial da cobra
		*/
    Snake(char direction, int row, int column);

    /*! Contrutor da classe Snake sem parametros
		*/
    Snake();

    /*! pega o tamanho total da cobra
    @return o tamanho da cobra
		*/
    int get_body_size();

    /*! Faz a cobra crescer na sua ultima posição
		*/
    void eat();

    /*! faz a cobra se mover para uma nova direção
    @param new_direction a nova direção
		*/
    void walk(char new_direction);

    /*! renderiza o mapa com a cobra e mostra os dados
    @param map o mapa onde esta cobra
    @param foods_left a quantidade restante de comdias
    @param lifes a quantidade de vidas que a cobra ainda possui
    @param score o score do jogador nesse level
		*/
    void render_map(std::vector<std::string> map, int foods_left, int lifes, int score);
    
    /*! Verifica se alguma parte da cobra esta nesse ponto
    @param row linha que sera verificada
    @param column coluna que sera verificada
    @return true caso a cobra esteja e false caso não
		*/
    bool snake_point(int row, int column);

    /*! verifica se a cobra comeu e aumenta ela caso sim
    @param map vetor contendo o mapa e a comida
    @param gamemode para saber caso a cobra irá crescer ou não
		*/
    bool verify_eat(std::vector<std::string> map, std::string game_mode);

    /*! verifica se a cobra bateu em si mesma ou em uma parede no mapa
    @param map o mapa a ser verificado
    @return true caso a cobra tenha batido e false caso não
		*/
    bool verify_collapse(std::vector<std::string> map);

    /*! habilita o modo a ser controlado pela "IA"
    @param map o mapa onde a cobra esta
    @return char com a direção pra onde a cobra irá
		*/
    char IAMode(std::vector<std::string> map);
};

#endif