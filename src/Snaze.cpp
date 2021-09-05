#include <iostream>
#include "SnakeGame.h"

using namespace std;

int main(int argc, char *argv[]){
    if(argc < 3) {
        cout << "Chamada incorreta do programa" << endl;
        return 1;
    }
    std::string file_name = argv[1];
    std::string game_mode = argv[2];
    bool loop = false;
    if(argc > 3) {
        std::string loopLevels = argv[3];
        if(loopLevels == "loop") {
            loop = true;
        }
    }

    SnakeGame game(file_name, game_mode, loop);
    
    game.loop(); //bloqueia aqui e só saí quando o jogo termina

    return 0;
}