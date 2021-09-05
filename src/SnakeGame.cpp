#include "SnakeGame.h"

#include <iostream>
#include <fstream>
#include <sstream>

#include <chrono> //por causa do sleep
#include <thread> //por causa do sleep

using namespace std;

/**
 * @brief função auxiliar para limpar o terminal
 */
void clearScreen(){
//some C++ voodoo here ;D
#if defined _WIN32
    system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
#elif defined (__APPLE__)
    system("clear");
#endif
}

/**
 * @brief função auxiliar para fazer o programa esperar por alguns milisegundos
 * @param ms a quantidade de segundos que o programa deve esperar
 */
void wait(int ms){
    this_thread::sleep_for(chrono::milliseconds(ms));
}

SnakeGame::SnakeGame(std::string file_name, std::string game_mode, bool loopLevels){
    this->file_name = file_name;
    this->game_mode = game_mode;
    this->loopLevels = loopLevels;
    choice = "";
    frameCount = 0;
    initialize_game();
}

void SnakeGame::initialize_game(){
    //carrega o nivel ou os níveis
    ifstream levelFile(this->file_name);
    int lineCount = 0;
    string line;
    int rows = 1;
    std::vector<std::string> map;
    std::vector<int> data;
    if(levelFile.is_open()){
        while(getline(levelFile, line)) {
            if(lineCount == 0) {
                data = get_level_data(line);
                rows = data[0];
            } else if(lineCount <= rows) {
                map.push_back(line);
            } else {
                Level level(data[0], data[1], data[2], map, this->game_mode);
                this->levels.push_back(level);
                map.clear();
                lineCount = 0;
                data = get_level_data(line);
                rows = data[0];
            }

            lineCount++;
        }
        Level new_level(data[0], data[1], data[2], map, this->game_mode);
        this->levels.push_back(new_level);
        this->actual_level = 0;
        /* while(getline(levelFile, line)){ //pega cada linha do arquivo
            if(lineCount > 0){ //ignora a primeira linha já que ela contem informações que não são uteis para esse exemplo
                maze.push_back(line);
            }
            lineCount++;
        } */
    }
    state = RUNNING;
}



void SnakeGame::process_actions(){
    //processa as entradas do jogador de acordo com o estado do jogo
    //nesse exemplo o jogo tem 3 estados, WAITING_USER, RUNNING e GAME_OVER.
    //no caso deste trabalho temos 2 tipos de entrada, uma que vem da classe Player, como resultado do processamento da IA
    //outra vem do próprio usuário na forma de uma entrada do teclado.
    switch(state){
        case WAITING_USER: //o jogo bloqueia aqui esperando o usuário digitar a escolha dele
            cin>>std::ws>>choice;
            break;
        default:
            // this->levels[this->actual_level].snake_walk(this->passosTeste[passos % this->passosTeste.size()]);
            // this->passos++;
            //nada pra fazer aqui
            this->levels[this->actual_level].IAMode();
            break;
    }

    if(this->levels[this->actual_level].verify_collapse()) {
        if(this->levels[this->actual_level].get_lifes() > 1) {
            this->levels[this->actual_level].reset();
            clearScreen();
            std::cout << "Você perdeu uma vida!" << std::endl;
            std::cout << "Você ainda tem " << this->levels[this->actual_level].get_lifes() << " vidas." << std::endl;
            std::cout << "Você deseja continuar? (s/n)" << std::endl;
            cin>>std::ws>>choice;
            if(choice == "n"){
                state = GAME_OVER;
                game_over();
            }
            // wait(2500);
        } else {
            if(++actual_level == this->levels.size()) {
                this->state = GAME_OVER;
            }
        }
    }
}

void SnakeGame::update(){
    //atualiza o estado do jogo de acordo com o resultado da chamada de "process_input"
    switch(state){
        case GAME_OVER:
            game_over();
            break;
        case RUNNING:
            // if(frameCount>0 && frameCount%10 == 0) //depois de 10 frames o jogo pergunta se o usuário quer continuar
            //     state = WAITING_USER;
            if(this->levels[this->actual_level].verify_win()) {
                this->actual_level++;
                if(this->loopLevels && this->actual_level == this->levels.size()) {
                    this->actual_level = this->actual_level % this->levels.size();
                    for(int i = 0; i < this->levels.size(); i++) {
                        this->levels[i].reset(false);
                    }
                }
                if(this->actual_level == this->levels.size()) {
                    cout << "PARABÉNS!!!!!" << std::endl;
                    cout << "VOCÊ VENCEU!!!" << std::endl;
                    wait(5000);
                    state = GAME_OVER;
                } else {
                    clearScreen();
                    cout << "Parabéns!! Você passou do nivel " << this->actual_level << std::endl;
                    cout << "Agora você jogara no nível " << this->actual_level + 1 << std::endl;
                    std::cout << "Você deseja continuar? (s/n)" << std::endl;
                    cin>>std::ws>>choice;
                    if(choice == "n"){
                        state = GAME_OVER;
                        game_over();
                    }
                    clearScreen();
                }
            }
            break;
        case WAITING_USER: //se o jogo estava esperando pelo usuário então ele testa qual a escolha que foi feita
            if(choice == "n"){
                state = GAME_OVER;
                game_over();
            }
            else{
                //pode fazer alguma coisa antes de fazer isso aqui
                state = RUNNING;
            }
            break;
        default:
            //nada pra fazer aqui
            break;
    }
}

void SnakeGame::render(){
    clearScreen();
    switch(state){
        case RUNNING:
            //desenha todas as linhas do labirinto
            std::cout << "Você esta no nível " << this->actual_level + 1 << std::endl;
            this->levels[this->actual_level].render();
            break;
        case WAITING_USER:
            cout<<"Você quer continuar com o jogo? (s/n)"<<endl;
            break;
        case GAME_OVER:
            cout<<"O jogo terminou!"<<endl;
            break;
    }
    frameCount++;
}

void SnakeGame::game_over(){
}

void SnakeGame::loop(){
    while(state != GAME_OVER){
        process_actions();
        update();
        render();
        wait(50);// espera 1 segundo entre cada frame
    }
}

std::vector<int> SnakeGame::get_level_data(std::string line) {
    istringstream is(line);
    int n;
    std::vector<int> data;
    while( is >> n)
        data.push_back(n);
    return data;
}
