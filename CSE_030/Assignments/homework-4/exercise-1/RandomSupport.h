//
// A small library for sampling random numbers from a uniform distribution
//
#ifndef RandomSupport_h
#define RandomSupport_h


#include <stdlib.h>
#include <ctime>


struct RNG{
private:
	int lower;
	int upper;

public:

	RNG(){
        srand(time(0));
		lower = 0;
		upper = 9;

	}

	RNG(int lower, int upper){
        srand(time(0));
		this->lower = lower;
		this->upper = upper;
	}

	int get(){
		return lower + (rand() % static_cast<int>(upper - lower + 1));
	}

	void setLimits(int lower, int upper){
		this->lower = lower;
		this->upper = upper;
	}

};

#endif