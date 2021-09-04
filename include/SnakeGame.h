#ifndef SnakeGame_h
#define SnakeGame_h
#include <iostream>
#include <vector>
#include <Level.h>


class SnakeGame{
    public:
        /**
        * @brief descreve os possíveis estados do jogo, fique à vontade para adicionar outros se necessário
        **/
        enum GameStates{
            RUNNING, //<! quando o jogo está executando o estado é RUNNING
            GAME_OVER, //<! quando o jogo deve terminar o estado é GAME_OVER
            WAITING_USER //<! quando o jogo deve esperar por uma entrada do usuário o estado é WAITING_USER
        };

    private:
        //<! atributos adicione outros se quiser
        std::vector<std::string> maze; //<! vector contendo o labirinto atual, pode ser interpretado como uma matriz
        int frameCount; //<! contador de frames, usado apenas como exemplo
        std::string choice; //<! usado na função process_actions para guardar a escolha do usuário
        GameStates state; //<! guarda o estado do jogo
        std::string file_name; //<! arquivo com a entrada do jogo
        std::vector<Level> levels; //<! vetor com todos levels que tem no jogo
        int actual_level; //<! int que indica em qual posição esta o level atual do jogo
        std::string game_mode; //<! string para indicar se o tipo de jogo é snake ou pacman

    public:
        /**
        * @brief construtor padrão, fique à vontade para adicionar parâmetros se desejar
        **/
        SnakeGame(std::string file_name, std::string game_mode);

        /**
        * @brief chamado no main, este loop executa o jogo indefinidamente até que o usuário escolha terminar!
        */
        void loop();

    private:
        std::vector<int> get_level_data(std::string line);
        /**
        * @brief realiza a inicialização geral do jogo, fique à vontade para adicionar parâmetros se achar que deve
        **/
        void initialize_game();

        /**
        * @brief atualiza o estado do jogo, basicamente movendo os objetos, sorteando novas posições de comida
        **/
        void update();

        /**
        * @brief processa as entradas do jogador
        **/
        void process_actions();

        /**
        * @brief testa o estado do jogo e desenha a tela correspondente
        **/
        void render();

        /**
        * @brief é chamada quando o jogo termina a fim de destruir/resetar elementos do estado do jogo
        **/
        void game_over();
};

#endif //SnakeGame_h