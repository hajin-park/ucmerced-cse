#include <iostream>
#include "TimeSupport.h"
#include "RandomSupport.h"

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = nullptr;
    }
};

struct Queue{
    Node* first;
    Node* last;

    Queue(){
        first = nullptr;
        last = nullptr;
    }

    void push(int x){
        Node* temp = new Node(x);

        if (last == nullptr){
            first = temp;
            last = first;
        }
        else{
            last->next = temp;
            last = last->next;
        }
    }

    int pop(){
        if (first != nullptr){
            int value = first->data;

            Node* temp = first;
            first = first->next;
            delete temp;
            return value;
        }
        else{
            throw std::logic_error("Can not pop from an empty queue.");
        }
    }

    bool search(int x){
        Node* temp = first;
        while (temp != nullptr){
            if (temp->data == x){
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
    
    ~Queue(){
        while (first != nullptr){
            pop();
        }
    }
};

struct HashTable {
private:
    Queue* data;
    int K;

    int f(int x){
        return x % K >= 0 ? x % K : (x % K) + K;
    }

public:
    HashTable(int K){
        this->K = K;
        data = new Queue[K];
    }

    void insert(int x){
        int i = f(x);
        data[i].push(x);
    }

    bool search(int x){
        int i = f(x);
        return data[i].search(x);
    }

    ~HashTable(){
        delete[] data;
    }

};


int main(){
    // Read the list size and sorting algorithm from the user
    int N;
    cout << "Problem size: ";
    cin >> N;

    // Declare an array of the appropriate size
    HashTable ht(10000);

    // Initialize a random number generator
    RNG rng(1, N);

    // Get the current time
    Timestamp start = current_time();

    // Fill the array with random numbers
    for (int i = 0; i < N; i++){
        int x = rng.get();

        ht.insert(x);
        
        // Perform a search
        ht.search(-1);
    }

    // Get the current time again
    Timestamp end = current_time();

    // The number of milliseconds that have elapsed between the 2 timestamps above
    int duration = time_diff(start, end);

    // Report the results
    cout << "Took " << duration << " ms. to complete on a collection of size " << N << endl;

    return 0;
}