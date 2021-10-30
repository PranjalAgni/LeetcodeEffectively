#include <stack>
#include <vector>
using namespace std;

unordered_map<int, vector<int>> buildGraph(vector<int>& jobs,
                                           vector<vector<int>>& deps) {
    unordered_map<int, vector<int>> graph;
    for (int job : jobs) {
        graph[job] = {};
    }

    for (vector<int> dep : deps) {
        vector<int> edges = graph[dep[0]];
        edges.push_back(dep[1]);
        graph[dep[0]] = edges;
    }

    return graph;
}

unordered_map<int, int> computeIndegreeOfGraph(vector<vector<int>>& deps) {
    unordered_map<int, int> incomingEdgesMap;
    for (vector<int> dep : deps) {
        incomingEdgesMap[dep[1]] += 1;
    }

    return incomingEdgesMap;
}

stack<int> getVerticiesWithIndegreeZero(vector<int>& jobs,
                                        unordered_map<int, int>& indegree) {
    stack<int> vertexWithIndegreeZero;
    for (int job : jobs) {
        if (indegree[job] == 0) {
            vertexWithIndegreeZero.push(job);
        }
    }

    return vertexWithIndegreeZero;
}

bool dfs(unordered_map<int, vector<int>>& graph, int job,
         unordered_map<int, bool>& visited) {
    if (visited[job]) return true;
    visited[job] = true;
    for (int neighbour : graph[job]) {
        bool isCycle = dfs(graph, neighbour, visited);
        if (isCycle) return true;
    }
    visited[job] = false;
    return false;
}

bool isCycleExist(vector<int>& jobs, unordered_map<int, vector<int>>& graph) {
    unordered_map<int, bool> visited;
    for (int job : jobs) {
        bool isCycle = dfs(graph, job, visited);
        if (isCycle) return true;
    }

    return false;
}

// Time: O(V + E) | Space: O(V + E)
// V = number of verticies (job)
// E = number of edges
vector<int> topologicalSort(vector<int> jobs, vector<vector<int>> deps) {
    unordered_map<int, vector<int>> graph = buildGraph(jobs, deps);
    bool isCycle = isCycleExist(jobs, graph);
    if (isCycle) return {};
    unordered_map<int, int> indegree = computeIndegreeOfGraph(deps);
    stack<int> vertexWithIndegreeZero =
        getVerticiesWithIndegreeZero(jobs, indegree);
    vector<int> topologicalOrder;

    while (!vertexWithIndegreeZero.empty()) {
        int job = vertexWithIndegreeZero.top();
        topologicalOrder.push_back(job);
        vertexWithIndegreeZero.pop();
        vector<int> neighbours = graph[job];
        for (int neighbour : neighbours) {
            indegree[neighbour] -= 1;
            if (indegree[neighbour] == 0) {
                vertexWithIndegreeZero.push(neighbour);
            }
        }
    }
    return topologicalOrder;
}
