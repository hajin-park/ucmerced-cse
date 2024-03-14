// Contributers:
// Miguel Diaz
// Edison Zhang
// Hajin Park

#ifndef MOVE_MANAGER_H
#define MOVE_MANANGER_HClass

#include <climits>
#include <limits>
#include "Reward.h"
#include "GameState.h"


// Option 1: human opponent
Vec playerMove(GameState game) {
    int x, y;
    while (true) {
        std::cout << (!game.currentTurn ? "(X) " : "(O) ") << "Enter your row: ";
        std::cin >> x;
        std::cout << (!game.currentTurn ? "(X) " : "(O) ") << "Enter your column: ";
        std::cin >> y;

        if (std::cin.fail()) {
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cout << "Invalid input. Please enter numeric values." << std::endl;
            continue;
        }

        if (x < 0 || x >= game.size || y < 0 || y >= game.size) {
            std::cout << "Move out of bounds. Please try again." << std::endl;
            continue;
        }

        if (game.grid[x][y] != -1) {
            std::cout << "Cell already occupied. Please try again." << std::endl;
            continue;
        }

        break;
    }
    return Vec(x, y);
}

// Option 2: easy AI opponent
Vec validMove(GameState game) {
    for (int i = 0; i < game.size; i++){
        for (int j = 0; j < game.size; j++){
            if (game.grid[i][j] == -1){
                return Vec(i, j);
            }
        }
    }

    return Vec(0, 0);
}

// Option 3: impossible AI opponent
Vec bestMove(GameState game) {
    Graph<GameState> stateSpace;
    Vertex<GameState>* start = new Vertex<GameState>(game);
    Vec move = { -1, -1};
    int maxVal = INT_MIN;

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

    for (size_t i = 0; i < start->neighbors.size(); ++i) {
        auto& neighbor = start->neighbors[i];
        int moveVal = getReward(neighbor->location, game.currentTurn);
        
        if (moveVal > maxVal) {
            std::cout << moveVal << std::endl;
            maxVal = moveVal;
            move.x = neighbor->location->data.lastMove.x;
            move.y = neighbor->location->data.lastMove.y;
        }
    }

    return move;
}

Vec opponentMove(int gameType, GameState game) {
    switch (gameType) {
        case 1: {
            return playerMove(game);
        }
        case 2: {
            return validMove(game);
        }
        case 3: {
            return bestMove(game);
        }
        default: {
            return Vec(0, 0);
        }
    }
}


#endif