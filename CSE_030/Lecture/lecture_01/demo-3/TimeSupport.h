//
// A small library for timing our programs
//

#ifndef TIME_SUPPORT_H
#define TIME_SUPPORT_H

#include <chrono>

typedef enum {
    sec,
    mill
} Unit;

typedef std::chrono::time_point<std::chrono::high_resolution_clock> Timestamp;

int time_diff(Timestamp start, Timestamp end, Unit u = mill){
    
    if (u == mill){
        auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
        
        return (int) diff;
    }
    else{
        auto diff = std::chrono::duration_cast<std::chrono::seconds>(end-start).count();
        
        return (int) diff;
    }
}


Timestamp current_time(){
    return std::chrono::high_resolution_clock::now();
}

#endif