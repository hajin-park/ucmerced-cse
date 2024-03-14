//
// A small library for timing our programs
//

#ifndef TimeSupport_h
#define TimeSupport_h

#include <chrono>

typedef enum {
    sec,
    mill
} Unit;

typedef std::chrono::time_point<std::chrono::high_resolution_clock> timestamp;

int time_diff(timestamp start, timestamp end, Unit u = mill){
    
    if (u == mill){
        auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
        
        return (int) diff;
    }
    else{
        auto diff = std::chrono::duration_cast<std::chrono::seconds>(end-start).count();
        
        return (int) diff;
    }
}


timestamp current_time(){
    return std::chrono::high_resolution_clock::now();
}

class TimeStamp{
    timestamp ts;
public:
    TimeStamp(){
        ts = current_time();
    }

    int operator-(TimeStamp& lhs){
        return time_diff(lhs.ts, ts);
    }
};

#endif