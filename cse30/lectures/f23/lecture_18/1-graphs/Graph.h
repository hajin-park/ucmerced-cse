#ifndef GRAPH_H
#define GRAPH_H

#include <ostream>
#include <ArrayList.h>
#include "Vertex.h"
#include <Queue.h>
#include <Stack.h>
#include "HashTable.h"

template <class T>
struct Waypoint{
    Waypoint<T>* parent;
    int weight;
    int partialCost;
    Vertex<T>* vertex;
    ArrayList<Waypoint<T>*> children;

    Waypoint(Vertex<T>* vertex, Waypoint<T>* parent){
        this->vertex = vertex;
        this->parent = parent;
        partialCost = 0;
    }

    Waypoint(Vertex<T>* vertex, Waypoint<T>* parent, int weight){
        this->vertex = vertex;
        this->parent = parent;
        this->weight = weight;
        partialCost = 0;
    }

    void addToCost(int val){
        partialCost += val;
    }

    void expand(){
        for (int i = 0; i < vertex->degree; i++){
            Neighbor<T>* neighbor = vertex->neighbors[i];
            Waypoint<T>* temp = new Waypoint(neighbor->location, this, neighbor->weight);
            temp->addToCost(partialCost + neighbor->weight);
            children.append(temp);
        }
    }
};

template <class T>
struct Frontier{
    ArrayList<Waypoint<T>*> list;

    void addToFront(Waypoint<T>* wp){
        list.prepend(wp);
    }

    void addToBack(Waypoint<T>* wp){
        list.append(wp);
    }

    void addSorted(Waypoint<T>* wp){
        list.append(wp);
        int j = list.size() - 1;
        while (j > 0 && list[j]->partialCost < list[j-1]->partialCost){
            Waypoint<T>* temp = list[j];
            list[j] = list[j-1];
            list[j-1] = temp;
            j--;
        }
    }

    int getCumulativeCost(Vertex<T>* v){
        for (int i = 0; i < list.size(); i++){
            if (list.get(i)->vertex == v){
                return list.get(i)->partialCost;
            }
        }
        return -1;
    }

    void remove(Vertex<T>* v){
        for (int i = 0; i < list.size(); i++){
            if (list.get(i)->vertex == v){
                list.remove(i);
                break;
            }
        }
    }

    Waypoint<T>* removeFront(){
        return list.removeFirst();
    }

    Waypoint<T>* removeBack(){
        return list.removeLast();
    }

    int length(){
        return list.size();
    }
};

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

    Waypoint<T>* bfs(Vertex<T>* start, Vertex<T>* end){
        Frontier<T> frontier;

        Waypoint<T>* initialNode = new Waypoint<T>(start, nullptr);
        frontier.addToBack(initialNode);

        HashTable<Vertex<T>*> seen(100, [](Vertex<T>* t) -> int {
            return (long)t % 100;
        });
        seen.add(start);

        Waypoint<T>* node = nullptr;

        while(frontier.length() > 0){

            node = frontier.removeFront();

            if (node->vertex == end){
                return node;
            }

            node->expand();
 
            for (int i = 0; i < node->children.size(); i++){
                Waypoint<T>* neighbor = node->children[i];

                if (!seen.search(neighbor->vertex)){
                    frontier.addToBack(neighbor);
                    seen.add(neighbor->vertex);
                }
            }
        }
        return nullptr;
    }

    Waypoint<T>* shortestPath(Vertex<T>* start, Vertex<T>* end){
        Frontier<T> frontier;

        Waypoint<T>* initialNode = new Waypoint<T>(start, nullptr);
        frontier.addToBack(initialNode);

        HashTable<Vertex<T>*> seen(100, [](Vertex<T>* t) -> int {
            return (long)t % 100;
        });
        seen.add(start);

        Waypoint<T>* node = nullptr;

        while(frontier.length() > 0){

            node = frontier.removeFront();

            if (node->vertex == end){
                return node;
            }

            node->expand();
 
            for (int i = 0; i < node->children.count; i++){
                Waypoint<T>* neighbor = node->children.get(i);

                if (!seen.search(neighbor->vertex)){
                    frontier.addSorted(neighbor);
                    seen.add(neighbor->vertex);
                }
                else{
                    int prev = frontier.getCumulativeCost(neighbor->vertex);
                    int curr = neighbor->partialCost;

                    if (prev != -1){
                        if (curr < prev){
                            frontier.remove(neighbor->vertex);
                            frontier.addSorted(neighbor);
                        }
                    }
                }
            }
        }
        return nullptr;
    }

};

template <class T>
std::ostream& operator<<(std::ostream& os, const Graph<T>& graph){
    for (int i = 0; i < graph.vertices.count; i++){
        os << graph.vertices.get(i) << '\n';
    }
    return os;
}

#endif