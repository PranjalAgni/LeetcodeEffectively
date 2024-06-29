// https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/

class Solution {
private:
    void dfs(int src, int par, unordered_map<int, vector<int>>& adjList, vector<int>& visited, stack<int>& orderStack) {
      if (visited[src]) return;
      visited[src] = 1;
      for (int& neighbour: adjList[src]) {
        if (visited[neighbour] == 0) {
          dfs(neighbour, src, adjList, visited, orderStack);
        }
      }
      
      orderStack.push(src);
    }
    vector<int> topologicalOrdering(int n, unordered_map<int, vector<int>>& adjList) {
        vector<int> visited(n, 0);
        stack<int> orderStack;
      
        for (int v = 0; v < n; v++) {
          if (visited[v] == 0) {
            dfs(v, -1, adjList, visited, orderStack);
          }
        }
      
        vector<int> order;
        while(!orderStack.empty()) {
          order.push_back(orderStack.top());
          orderStack.pop();
        }
      
        return order;
    }
  
    unordered_map<int, vector<int>> buildGraph(int n, vector<vector<int>>& edges) {
      unordered_map<int, vector<int>> adjList;
      for (int idx = 0; idx < n; idx++) {
        vector<int> current;
        for (int& v: edges[idx]) {
          adjList[idx].push_back(v);
        }
      }
      
      return adjList;
    }
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adjList = buildGraph(n, edges);
        vector<int> order = topologicalOrdering(n, adjList);
        for (int& o: order) cout << o << " ";
        cout << endl;
        return {};
    }
};