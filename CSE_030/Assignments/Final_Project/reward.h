#ifndef REWARD_H
#define REWARD_H

#include "GameState.h"

int getReward(Vertex<GameState>* start, int player){
    if (start->neighbors.size() == 0){
        int currPlayer = start->data.currentTurn;
        if (start->data.hasWon(player)){
            return 100;
        }
        else if (start->data.hasWon(!player)){
            return -100;
        }
        else{
            return 50;
        }
    }
    else{
        int reward = getReward(start->neighbors[0]->location, player);
        for (int i = 1; i < start->neighbors.size(); i++){
            int curr = getReward(start->neighbors[i]->location, player);
            if (start->data.currentTurn == player){
                if (curr > reward){
                    reward = curr;
                }
            }
            else{
                if (curr < reward){
                    reward = curr;
                }
            }
        }
        return reward;
    }
}

#endif