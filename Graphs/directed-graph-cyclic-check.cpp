#include <vector>
using namespace std;

bool dfs(vector<vector<int>>& edges, int vertex,
         unordered_map<int, bool>& nodeVisited) {
    cout << vertex << endl;
    if (nodeVisited[vertex]) return true;
    nodeVisited[vertex] = true;

    for (int neighbour : edges[vertex]) {
        bool isCycleExists = dfs(edges, neighbour, nodeVisited);
        if (isCycleExists) return true;
    }

    nodeVisited[vertex] = false;
    return false;
}

// Time: O(V + E) | Space: O(V)
bool cycleInGraph(vector<vector<int>> edges) {
    int vertex = edges.size();
    unordered_map<int, bool> nodeVisited;

    for (int v = 0; v < vertex; v++) {
        bool isCycleExists = dfs(edges, v, nodeVisited);
        if (isCycleExists) return true;
    }

    return false;
}
