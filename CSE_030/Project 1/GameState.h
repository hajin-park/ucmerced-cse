#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <iostream>

struct Vec{
    int x;
    int y;

    Vec(){
        x = 0;
        y = 0;
    }

    Vec(int x, int y){
        this->x = x;
        this->y = y;
    }

    void set(int x, int y){
        this->x = x;
        this->y = y;
    }
};

std::ostream& operator<<(std::ostream& os, const Vec& v){
    os << "(" << v.x << ", " << v.y << ")";

    return os;
}

struct GameState;
std::ostream& operator<<(std::ostream& os, const GameState& state);

struct GameState{
    int** grid;
    bool currentTurn;
    int size;
    int turnCount;

    bool done;
    Vec lastMove;

    GameState(){
        size = 3;
        currentTurn = 0;
        turnCount = 0;
        done = false;

        lastMove.set(-1, -1);

        grid = new int*[size];

        for (int i = 0; i < size; i++){
            grid[i] = new int[size];
            for (int j = 0; j < size; j++){
                grid[i][j] = -1;
            }
        }
    }

    GameState(int size){
        this->size = size;
        currentTurn = 0;
        turnCount = 0;
        done = false;

        lastMove.set(-1, -1);

        grid = new int*[size];

        for (int i = 0; i < size; i++){
            grid[i] = new int[size];
            for (int j = 0; j < size; j++){
                grid[i][j] = -1;
            }
        }
    }

    GameState(const GameState& other){
        size = other.size;
        currentTurn = other.currentTurn;
        turnCount = other.turnCount;
        done = other.done;
        lastMove = other.lastMove;

        grid = new int*[size];

        for (int i = 0; i < size; i++){
            grid[i] = new int[size];
            for (int j = 0; j < size; j++){
                grid[i][j] = other.grid[i][j];
            }
        }
    }
    

    bool operator==(const GameState& other){
        bool sizeMatch = size == other.size;
        bool currentTurnMatch = currentTurn == other.currentTurn;
        bool turnCountMatch = turnCount == other.turnCount;
        bool doneMatch = done == other.done;
        bool lastMoveMatch = lastMove.x == other.lastMove.x && lastMove.y == other.lastMove.y;
        if (sizeMatch && currentTurnMatch && turnCountMatch && doneMatch && lastMoveMatch){
            for (int i = 0; i < size; i++){
                for (int j = 0; j < size; j++){
                    if (grid[i][j] != other.grid[i][j]){
                        return false;
                    }
                }
            }
            
            return true;
        }
        else{
            return false;
        }
    }

    GameState& operator=(const GameState& other){
        currentTurn = other.currentTurn;
        turnCount = other.turnCount;
        done = other.done;
        lastMove = other.lastMove;

        if (size == other.size){
            for (int i = 0; i < size; i++){
                for (int j = 0; j < size; j++){
                    grid[i][j] = other.grid[i][j];
                }
            }
        }
        else{
            
            for (int i = 0; i < size; i++){
                delete[] grid[i];
            }
            delete[] grid;

            size = other.size;

            grid = new int*[size];

            for (int i = 0; i < size; i++){
                grid[i] = new int[size];
                for (int j = 0; j < size; j++){
                    grid[i][j] = other.grid[i][j];
                }
            }
        }

        return *this;
    }

    bool hasWon(int player){
        for (int i = 0; i < size; i++){
            int count = 0;
            for (int j = 0; j < size; j++){
                if (grid[i][j] == player){
                    count++;
                }
            }
            if (count == size){
                return true;
            }
        }
        for (int i = 0; i < size; i++){
            int count = 0;
            for (int j = 0; j < size; j++){
                if (grid[j][i] == player){
                    count++;
                }
            }
            if (count == size){
                return true;
            }
        }
        int mainDiagCount = 0;
        for (int i = 0; i < size; i++){
            if (grid[i][i] == player){
                mainDiagCount++;
            }
        }
        if (mainDiagCount == size){
            return true;
        }

        int secondaryDiagCount = 0;
        for (int i = 0; i < size; i++){
            if (grid[i][size-1-i] == player){
                secondaryDiagCount++;
            }
        }
        if (secondaryDiagCount == size){
            return true;
        }
        

        return false;
    }

    bool play(int x, int y){
        if (grid[x][y] != -1){
            return false;
        }

        grid[x][y] = currentTurn;
        currentTurn = !currentTurn;
        turnCount++;
        lastMove.set(x, y);

        if (turnCount == size * size){
            done = true;
        }
        else if (hasWon(0) || hasWon(1)){
            done = true;
        }

        return true;
    }

    ~GameState(){
        for (int i = 0; i < size; i++){
            delete[] grid[i];
        }
        delete[] grid;
    }
};

std::ostream& operator<<(std::ostream& os, const GameState& state){
    os << "   ";
    for (int j = 0; j < state.size; j++){
        os << " " << j << "  ";
    }
    os << std::endl;
    os << "   ";
    for (int j = 0; j < state.size; j++){
        os << "--- ";
    }
    os << std::endl;
    for (int i = 0; i < state.size; i++){
        os << i << " ";
        for (int j = 0; j < state.size; j++){
            char c = ' ';
            if (state.grid[i][j] == 0){
                c = 'X';
            }
            else if (state.grid[i][j] == 1){
                c = 'O';
            }
            os << "| " << c << " ";
            if (j == state.size - 1) os << "|";
        }
        os << std::endl << "   ";
        for (int j = 0; j < state.size; j++){
            os << "--- ";
        }
        os << std::endl;
    }

    return os;
}

#endif