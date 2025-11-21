#include <iostream>
#include <vector>
#include <limit>
using namespace std;

int main(){

  int V; // no. of vertices
  int E; // no. of edges
  cin>>V;
  cin>>E;

  int** W = new int[V];
  for(int i = 0; i < V; i++){
    W[i] = new int[V];
  }

  vector<int>* G = new vector<int>[V];
  for(int i = 0; i < E; i++){
    int u,v,w;
    cin>>u>>v>>w;
    W[u][v] = w;
    W[v][u] = w;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  
  vector<int> Q;
  int* parents = new int[V];
  int* keys = new int[V];
  for(int i = 0; i < V; i++){
    parents[i] = null;
//    keys[i] = INT_MAX;
      keys[i] = 1000000;
  }

  // set keys[i] to 0
  // put all v into Q

  while(!Q.empty()){
    // find vertex which has min in keys: for loop in Q
    // remove element at index 'u' from Q
    for(int v : G[u]){
//    for(int i = 0; i < G[u].size(); i++){
//      int v = G[u][i];
      if(Q.contains(v) && W[u][v] < keys[v]){
        parents[v] = u;
        keys[v] = W[u][v];
      }
    }
  }
  
  // print parents from index 1

  return 0;
}















