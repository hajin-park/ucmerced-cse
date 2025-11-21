#include <iostream>

using namespace std;

struct Link{
    int data;
    Link* next;

    Link(){
        data = 0;
        next = nullptr;
    }

    Link(int data){
        this->data = data;
        next = nullptr;
    }
};

int main(int argc, char* argv[]){

    return 0;
}