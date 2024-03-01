#include <iostream>
#include "GameState.h"

using namespace std;

int main(){
    GameState game;

    game.play(0, 0);
    game.play(1, 1);
    cout << game << endl;
    
    return 0;
}