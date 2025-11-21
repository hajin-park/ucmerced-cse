#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Helper function to perform DFS and record finish times
void DFS(vector<int>* G, bool* seen, int* f, int v, int& time) {
    seen[v] = true;
    for (int u : G[v]) {
        if (!seen[u]) {
            DFS(G, seen, f, u, time);
        }
    }
    f[v] = time++;
}

// Helper function to perform DFS on the transpose graph and find SCCs
void DFS2(vector<int>* GT, bool* seen, vector<int>& scc, int v) {
    seen[v] = true;
    scc.push_back(v);
    for (int u : GT[v]) {
        if (!seen[u]) {
            DFS2(GT, seen, scc, u);
        }
    }
}

// Function to perform argsort, mimicking Python's numpy.argsort functionality
vector<int> argsort(const int* arr, int size) {
    vector<int> indices(size);
    iota(indices.begin(), indices.end(), 0);

    sort(indices.begin(), indices.end(), [&arr](int i1, int i2) {
        return arr[i1] > arr[i2]; // Sort indices based on comparing values in arr
    });

    return indices;
}

int main() {
    int V; // Number of vertices
    int E; // Number of edges
    cin >> V >> E;

    vector<int>* G = new vector<int>[V];
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
    }

    // Building the transpose of the graph
    vector<int>* GT = new vector<int>[V];
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < G[i].size(); j++) {
            int u = i;
            int v = G[i][j];
            GT[v].push_back(u);
        }
    }

    bool* seen = new bool[V]();
    int* f = new int[V]();
    int time = 0;
    for (int i = 0; i < V; i++) {
        if (!seen[i]) {
            DFS(G, seen, f, i, time);
        }
    }

    vector<int> af = argsort(f, V); // Descending order of finish times
    fill_n(seen, V, false); // Reset seen array for second pass
    int* res = new int[V];

    for (int i = 0; i < V; i++) {
        int v = af[i];
        if (!seen[v]) {
            vector<int> scc;
            DFS2(GT, seen, scc, v);
            int sccid = *min_element(scc.begin(), scc.end());
            for (int u : scc) {
                res[u] = sccid;
            }
        }
    }

    for (int i = 0; i < V; i++) {
        cout << res[i] << endl;
    }

    // Clean up dynamically allocated memory
    delete[] G;
    delete[] GT;
    delete[] seen;
    delete[] f;
    delete[] res;

    return 0;
}
