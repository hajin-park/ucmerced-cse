// Contributers:
// Hajin Park
// Aram Shkhyan


#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

#include <iostream>
#include <ostream>
#include <stdexcept>


// ============= ARRAYLIST =============

template <class T>
struct ArrayList{
    T* data;
    int capacity;
    int count;

    // Helper functions
    bool linear_search(const T& value){
        for (int i = 0; i < count; i++){
            if (data[i] == value){
                return true;
            }
        }
        return false;
    }

    bool binary_search(const T& value){
        int left = 0;
        int right = count;

        while (left <= right){
            int mid = (left + right) / 2;
            if (data[mid] == value){
                return true;
            }
            else if (data[mid] > value){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return false;
    }


    void selection_sort(){
        for (int i = 0; i < count; i++){
            T minVal = data[i];
            int minPos = i;
            for(int j = i; j < count; j++){
                if (data[j] < minVal){
                    minVal = data[j];
                    minPos = j;
                }
            }
            T temp = data[i];
            data[i] = data[minPos];
            data[minPos] = temp;
        }
    }

    void insertion_sort(){
        for (int i = 1; i < count; i++){
            int j = i;
            while (j > 0 && data[j-1] > data[j]){
                T temp = data[j];
                data[j] = data[j-1];
                data[j-1] = temp;
                j--;
            }
        }
    }


    // ================== START QUICKSORT ==================

    int partition(int start, int end){
        T pivot = data[start];

        int count = 0;
        for (int i = start+1; i <= end; i++){
            if (data[i] <= pivot){
                count++;
            }
        }

        int pivotIndex = start + count;

        T temp = data[start];
        data[start] = data[pivotIndex];
        data[pivotIndex] = temp;


        int left = start;
        int right = end;

        while (left < pivotIndex && right > pivotIndex){
            while(data[left] <= data[pivotIndex]){
                left++;
            }
            while (data[right] >= data[pivotIndex]){
                right--;
            }
            if (left < pivotIndex && right > pivotIndex){
                T temp = data[left];
                data[left] = data[right];
                data[right] = temp;
            }

        }
        return pivotIndex;
    }
 
    void quickSort(int start, int end) {
        if (start >= end)
            return;
    
        int p = partition(start, end);

        quickSort(start, p - 1);
    
        quickSort(p + 1, end);
    }

    void quick_sort(){
        quickSort(0, count - 1);
    }

    // =================== END QUICKSORT ===================
                    
public:
    ArrayList(){
        capacity = 1;
        count = 0;
        data = new T[capacity];
    }

    void append(T value){
        data[count] = value;
        count++;

        if (count == capacity){

            int oldCapacity = capacity;
            capacity *= 2;

            T* temp = new T[capacity];

            for (int i = 0; i < oldCapacity; i++){
                temp[i] = data[i];
            }

            T* oldLocation = data;
            data = temp;
            delete[] oldLocation;
        }
    }

    void add(T value){
        append(value);
        insertion_sort();
    }

    int size() const{
        return count;
    }

    T& operator[](int index){
        return data[index];
    }

    T& get(int index) const{
        return data[index];
    }

    bool search(const T& value){
        return linear_search(value);
    }

    void sort(){
        insertion_sort();
    }

    ~ArrayList(){
        delete[] data;
    }
};

template <class T>
std::ostream& operator<<(std::ostream& os, ArrayList<T>& list){
    for (int i = 0; i < list.size(); i++){
        os << list[i] << " ";
    }

    return os;
}

// ============= ARRAYLIST =============

// ============ LINKEDLIST =============

template <class T>
class LinkedList;

template <class T>
struct Link{
    T data;
    Link* next;
    Link* prev;

    Link(){
        data = 0;
        next = nullptr;
        prev = nullptr;
    }

    Link(T data){
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
};

template <class T>
std::ostream& operator<<(std::ostream& os, const LinkedList<T>& list){
    Link<T>* curr = list.front;
    while (curr != nullptr){
        os << curr->data;
        if (curr->next != nullptr) os << ", ";
        curr = curr->next;
    }

    return os;
}

template<class T>
class LinkedList{
protected:
    Link<T>* front;
    Link<T>* back;
    int count;
public:
    LinkedList(){
        front = nullptr;
        back = nullptr;
        count = 0;
    }
    
    void append(T value){
        if (front == nullptr){
            // Appending to an empty list
            front = new Link<T>(value);
            back = front;
        }
        else{
            // Appending to list with elements
            Link<T>* temp = new Link<T>(value);
            temp->prev = back;
            back->next = temp;
            back = temp;
        }
        count++;
    }

    void prepend(T value){
        if (front == nullptr){
            // Prepending to an empty list
            front = new Link<T>(value);
            back = front;
        }
        else{
            // Prepending to a list with elements
            Link<T>* temp = new Link<T>(value);
            temp->next = front;
            front->prev = temp;
            front = temp;
        }
        count++;
    }

    T removeFirst(){
        if (front == nullptr){
            throw std::logic_error("Can not remove from an empty list");
        }
        if (count == 1){
            T x = front->data;
            delete front;
            front = nullptr;
            back = nullptr;
            count--;
            return x;
        }
        else{
            T x = front->data;
            Link<T>* old = front;
            front = front->next;
            front->prev = nullptr;
            delete old;
            count--;
            return x;
        }
    }

    T peek() const {
        if (front == nullptr){
            throw std::logic_error("Can not peek into an empty list");
        }
        return front->data;
    }
    
    T removeLast(){
        // Your code goes here
        if (front == nullptr){
            throw std::logic_error("Can not remove from an empty list");
        }
        if (front == back){
            T x = front->data;
            delete front;
            front = nullptr;
            back = nullptr;
            count--;
            return x;
        } else{
            T x = back->data;
            Link<T>* old = back;
            back = back->prev;
            back->next = nullptr;
            delete old;
            count--;
            return x;
        } 
    } 

    int size() const {
        return count;
    }

    bool isEmpty() const {
        return count == 0;
    }

    void reverse(){
        Link<T>* oldFront = front;
        front = back;
        back = oldFront;

        Link<T>* curr = front;
        while(curr != nullptr){
            Link<T>* temp = curr->next;
            curr->next = curr->prev;
            curr->prev = temp;
            curr = curr->next;
        }
    }

    friend std::ostream& operator<<<>(std::ostream& os, const LinkedList& list);

    friend struct TestLinkedList;

};

// ============ LINKEDLIST =============

// =============== QUEUE ===============

template <class T>
class Queue;

template <class T>
std::ostream& operator<<(std::ostream& os, const Queue<T>& q);


template <class T>
class Queue{
    LinkedList<T> elements;
public:
    void enqueue(T item){
        elements.append(item);
    }
    T dequeue(){
        return elements.removeFirst();
    }
    T peek() const{
        return elements.peek();
    }
    bool isEmpty() const {
        return elements.isEmpty();
    }
    int length() const {
        return elements.size();
    }

    friend std::ostream& operator<<<>(std::ostream& os, const Queue<T>& q);
};

template <class T>
std::ostream& operator<<(std::ostream& os, const Queue<T>& q){
    os << q.elements;
    return os;
}

// ================ QUEUE ================

// ================ STACK ================

template <class T>
class Stack;

template <class T>
std::ostream& operator<<(std::ostream& os, const Stack<T>& q);


template <class T>
class Stack{
    LinkedList<T> elements;
public:
    void push(T item){
        elements.prepend(item);
    }
    T pop(){
        return elements.removeFirst();
    }
    T peek() const{
        return elements.peek();
    }
    bool isEmpty() const {
        return elements.isEmpty();
    }
    int length() const {
        return elements.size();
    }
    friend std::ostream& operator<<<>(std::ostream& os, const Stack<T>& q);
};

template <class T>
std::ostream& operator<<(std::ostream& os, const Stack<T>& q){
    os << q.elements;
    return os;
}

// ================ STACK ================

// =============== VERTEX ================

template <class T>
struct Vertex;

template <class T>
struct Neighbor{
    int weight;
    Vertex<T>* location;

    Neighbor(Vertex<T>* vertex, int label){
        location = vertex;
        weight = label;
    }
};

template <class T>
struct Vertex{
    T data;
    int degree;
    ArrayList<Vertex*>* adjList;
    ArrayList<Neighbor<T>*> neighbors;

    Vertex(){
        adjList = nullptr;
    }

    Vertex(T value){
        data = value;
        adjList = nullptr;
        degree = 0;
    }

    void addNeighbor(Vertex* vertex){
        if (adjList == nullptr){
            adjList = new ArrayList<Vertex*>();
        }
        adjList->append(vertex);
        degree++;
    }
    void addNeighbor(Vertex* vertex, int weight){
        degree++;
        neighbors.append(new Neighbor<T>(vertex, weight));
    }

    ~Vertex(){
        delete adjList;
    }
};

template <class T>
std::ostream& operator<<(std::ostream& os, Vertex<T>& v){
    
    os << "Vertex:" << std::endl; 
    os << v.data << std::endl;
    os << "Neighbors:" << std::endl;
    for (int i = 0; i < v.degree; i++){
        os << v.neighbors[i]->location->data << std::endl;
    }

    return os;
}

// =============== VERTEX ================

// ================ GRAPH ================

template <class T>
struct Graph{

    ArrayList<Vertex<T>*> vertices;

    void addVertex(Vertex<T>* v){
        vertices.append(v);
    }

    void addEdge(Vertex<T>* u, Vertex<T>* v, int label){
        u->addNeighbor(v, label);
        v->addNeighbor(u, label);
    }

    void addDirectedEdge(Vertex<T>* u, Vertex<T>* v, int label = 0){
        u->addNeighbor(v, label);
    }

    ~Graph(){
        for (int i = 0; i < vertices.size(); i++){
            delete vertices[i];
        }
    }

};

template <class T>
std::ostream& operator<<(std::ostream& os, const Graph<T>& graph){
    for (int i = 0; i < graph.vertices.size(); i++){
        os << graph.vertices[i] << '\n';
    }
    return os;
}

// ================ GRAPH ================

#endif