#ifndef NODE_H
#define NODE_H

template <class T>
struct Node{
    T data;
    Node* next;

    Node(T value){
        data = value;
        next = nullptr;
    }

    bool operator==(const Node& other){
        return data == other.data;
    }
};

#endif