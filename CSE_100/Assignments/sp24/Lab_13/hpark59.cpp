#include <iostream>
#include <vector>
#include <limits>  // Correct spelling
using namespace std;

int main() {
    int V; // Number of vertices
    int E; // Number of edges
    cin >> V >> E;

    // Initialize weight matrix and adjacency list
    int** W = new int*[V];
    for (int i = 0; i < V; i++) {
        W[i] = new int[V];
        fill(W[i], W[i] + V, INT_MAX); // Initialize weights with INT_MAX
    }

    vector<int>* G = new vector<int>[V];
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        W[u][v] = w;
        G[u].push_back(v);
    }

    // Initialize distances from source
    vector<int> dist(V, INT_MAX);
    dist[0] = 0;

    // Relax edges up to V-1 times
    for (int i = 0; i < V - 1; i++) {
        for (int u = 0; u < V; u++) {
            for (int v : G[u]) {
                if (dist[u] != INT_MAX && dist[v] > dist[u] + W[u][v]) {
                    dist[v] = dist[u] + W[u][v];
                }
            }
        }
    }

    // Check for negative-weight cycles
    for (int u = 0; u < V; u++) {
        for (int v : G[u]) {
            if (dist[u] != INT_MAX && dist[v] > dist[u] + W[u][v]) {
                cout << "FALSE" << endl;
                return 0; // Stop execution as soon as a negative cycle is detected
            }
        }
    }

    cout << "TRUE" << endl;
    // Print out distances
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX) {
            cout << "INFINITY" << endl;
        } else {
            cout << dist[i] << endl;
        }
    }

    // Clean up dynamically allocated memory
    for (int i = 0; i < V; i++) {
        delete[] W[i];
    }
    delete[] W;
    delete[] G;

    return 0;
}
