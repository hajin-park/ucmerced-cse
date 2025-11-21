#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    int V; // Number of vertices
    int E; // Number of edges
    cin >> V >> E;

    // Initialize weight matrix and graph adjacency list
    int** W = new int*[V];
    vector<int>* G = new vector<int>[V];
    for (int i = 0; i < V; i++) {
        W[i] = new int[V];
        fill(W[i], W[i] + V, INT_MAX); // Initialize with INT_MAX to represent no direct connection
    }

    // Read edges and their weights
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        W[u][v] = w;
        W[v][u] = w;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    // Setup for Prim's algorithm
    vector<bool> inMST(V, false); // Tracks if a vertex is in the MST
    vector<int> key(V, INT_MAX); // Key values used to pick minimum weight edge
    vector<int> parent(V, -1); // Array to store constructed MST

    // Priority queue simulation with vector, start from the root vertex 0
    key[0] = 0;
    vector<int> pq(V); // Priority queue to store vertex indices
    iota(pq.begin(), pq.end(), 0); // Fill pq with 0, 1, ..., V-1

    while (!pq.empty()) {
        // Find the vertex with the minimum key value
        int u = *min_element(pq.begin(), pq.end(), [&](int i, int j) { return key[i] < key[j] && !inMST[i]; });

        // Remove u from pq
        pq.erase(remove(pq.begin(), pq.end(), u), pq.end());
        inMST[u] = true; // Add u to MST set

        // For every adjacent vertex v of u
        for (int v : G[u]) {
            // If v is not in MST and weight of u-v is less than key of v
            if (!inMST[v] && W[u][v] < key[v]) {
                parent[v] = u;
                key[v] = W[u][v];
            }
        }
    }

    // Output parent of each vertex starting from index 1
    for (int i = 1; i < V; i++) {
        cout << parent[i] << endl;
    }

    // Free dynamically allocated memory
    for (int i = 0; i < V; i++) {
        delete[] W[i];
    }
    delete[] W;
    delete[] G;

    return 0;
}
