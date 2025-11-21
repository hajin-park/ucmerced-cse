#ifndef VERTEX_H
#define VERTEX_H
#include <ArrayList.h>
#include <ostream>

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
};

template <class T, class E>
std::ostream& operator<<(std::ostream& os, Vertex<T>* v){
    

    for (int i = 0; i < v->degree; i++){
        os << v->data << " -- "  << v->neighbors.get(i)->location->data << " -- " << v->neighbors.get(i)->weight << '\n';
        // os << (v->neighbors[i])->data;
    }

    return os;
}

#endif