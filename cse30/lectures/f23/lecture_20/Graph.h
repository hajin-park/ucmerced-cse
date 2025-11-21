#ifndef GRAPH_H
#define GRAPH_H

#include <ostream>
#include <ArrayList.h>
#include "Vertex.h"
#include <Queue.h>
#include <Stack.h>


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

#endif