#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

void dfs(int u, const vector<vector<int>>& adjList, vector<int>& ids, vector<int>& low, vector<bool>& onStack, stack<int>& st, vector<int>& sccID, vector<int>& componentMin) {
    static int time = 0;
    st.push(u);
    onStack[u] = true;
    ids[u] = low[u] = ++time;

    // Process all adjacent vertices
    for (int v : adjList[u]) {
        if (ids[v] == -1) { // Vertex v has not been visited
            dfs(v, adjList, ids, low, onStack, st, sccID, componentMin);
            low[u] = min(low[u], low[v]);
        } else if (onStack[v]) { // Vertex v is in the stack and hence in the current SCC
            low[u] = min(low[u], ids[v]);
        }
    }

    // Check if the current vertex is a root of an SCC
    if (ids[u] == low[u]) {
        int sccMin = u; // Initialize the minimum index of the SCC
        while (true) {
            int v = st.top();
            st.pop();
            onStack[v] = false;
            sccID[v] = u; // Initially assign the root index as the SCC ID
            sccMin = min(sccMin, v);
            if (v == u) {
                break;
            }
        }
        componentMin[u] = sccMin; // Assign the minimum vertex index of this SCC
    }
}

vector<int> findSCC(int n, const vector<pair<int, int>>& edges) {
    vector<vector<int>> adjList(n);
    for (const auto& edge : edges) {
        adjList[edge.first].push_back(edge.second);
    }

    vector<int> ids(n, -1), low(n, -1), sccID(n), componentMin(n);
    vector<bool> onStack(n, false);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        if (ids[i] == -1) {
            dfs(i, adjList, ids, low, onStack, st, sccID, componentMin);
        }
    }

    // Assign the correct smallest index to each vertex in its SCC
    for (int i = 0; i < n; i++) {
        sccID[i] = componentMin[sccID[i]];
    }

    return sccID;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
    }

    vector<int> sccIds = findSCC(n, edges);

    for (int id : sccIds) {
        cout << id << endl;
    }

    return 0;
}
