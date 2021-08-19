#include <iostream>
#include "SnakeGame.h"

using namespace std;

int main(int argc, char *argv[]){
    std::string file_name = argv[1];
    SnakeGame game(file_name);
    
    game.loop(); //bloqueia aqui e só saí quando o jogo termina

    return 0;
}