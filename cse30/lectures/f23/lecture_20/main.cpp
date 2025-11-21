#include <iostream>
#include <system_error>
#include "GameState.h"
#include "Graph.h"
#include "Vertex.h"
#include <Queue.h>

using namespace std;


Vec validMove(GameState game){
    for (int i = 0; i < game.size; i++){
        for (int j = 0; j < game.size; j++){
            if (game.grid[i][j] == -1){
                return Vec(i, j);
            }
        }
    }
    return Vec(0,0);
}

Vec findBestMove(GameState game){
    Graph<GameState> stateSpace;
    Vertex<GameState>* start = new Vertex<GameState>(game);

    stateSpace.addVertex(start);

    Queue<Vertex<GameState>*> frontier;
    frontier.enqueue(start);

    while (!frontier.isEmpty()){
        Vertex<GameState>* curr = frontier.dequeue();
        if (!curr->data.done){
            for(int i = 0; i < game.size; i++){
                for (int j = 0; j < game.size; j++){
                    if(curr->data.grid[i][j] == -1){
                        GameState next = curr->data;
                        next.play(i, j);
                        Vertex<GameState>* successor = new Vertex<GameState>(next);
                        stateSpace.addVertex(successor);
                        stateSpace.addDirectedEdge(curr, successor);
                        if (!successor->data.done){
                            frontier.enqueue(successor);
                        }
                    }
                }
            }
        }
    }


    // for every successor of start, call getReward(successor, player1)


    return Vec(0,0);
}

int main(){
    GameState game;

    while(!game.done){
        system("clear");
        cout << game << endl;

        int x, y;

        if (game.currentTurn){
            Vec move = findBestMove(game);
            x = move.x;
            y = move.y;
        }
        // else{
            cout << endl;
            cout << "Enter move for (" << (!game.currentTurn ? "X" : "O") << "): ";
            cin >> x >> y;
        // }

        game.play(x, y);
    }

    system("clear");
    cout << game << endl;
    cout << endl;
    if (game.hasWon(0)){
        cout << "Player X has won" << endl;
    }
    else if (game.hasWon(1)){
        cout << "Player O has won" << endl;
    }
    else {
        cout << "It's a tie" << endl;
    }
    return 0;
}