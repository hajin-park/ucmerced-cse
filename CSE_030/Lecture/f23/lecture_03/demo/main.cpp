#include <iostream>
#include <ostream>
#include <stdexcept>

using namespace std;

struct Container{

    int* arr;

    Container(){
        cout << "Creating a Container" << endl;
        arr = new int[5];
        for (int i = 0; i < 5; i++){
            arr[i] = 0;
        }
    }

    Container(const Container& other){
        cout << "Creating a copy of a Container" << endl;
        arr = new int[5];
        for (int i = 0; i < 5; i++){
            arr[i] = other.arr[i];
        }
    }

    Container& operator=(const Container& other){
        for (int i = 0; i < 5; i++){
            arr[i] = other.arr[i];
        }
        return *this;
    }

    int first() const {
        return arr[0];
    }

    void insert(int value, int pos){
        if (pos < 0 || pos > 4){
            throw logic_error("Array index out of bounds.");
        }
        arr[pos] = value;
    }

    int size() const {
        return 5;
    }

    ~Container(){
        cout << "Destroying a Container" << endl;
        delete[] arr;
    }
};

ostream& operator<<(ostream& os, const Container& container){
    for (int i = 0; i < container.size(); i++){
        os << container.arr[i];
        if (i < container.size()-1){
            os << ", ";
        }
    }
    return os;
}

int main(int argc, char* argv[]){

    Container c;

    c.insert(15, 0);
    c.insert(3, 1);
    c.insert(7, 2);

    cout << "c = " << c << endl;

    Container d;
    d = c; 

    c.arr[0] = 99;

    cout << "c = " << c << endl;
    cout << "d = " << d << endl;

    return 0;
}