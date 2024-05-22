// https://leetcode.com/problems/sum-of-distances-in-tree/

class Solution {
private:
    unordered_map<int, vector<int>> buildGraph(vector<vector<int>>& edges) {
      unordered_map<int, vector<int>> graph;
      for (vector<int>& edge: edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
      }
      
      return graph;
    }
  
    int dfsfill(unordered_map<int, vector<int>>& graph, int currentNode, int prevNode, vector<int>& subtreeSizes, int& rootDistance, int depth) {
      rootDistance += depth;
      for (int& node: graph[currentNode]) {
        if (node == prevNode) continue;
        subtreeSizes[currentNode] += 1 + dfsfill(graph, node, currentNode, subtreeSizes, rootDistance, depth + 1);
      }
      
      return subtreeSizes[currentNode];
    }
  
    void dfs2(unordered_map<int, vector<int>>& graph, vector<int>& subtreeSizes, vector<int>& distances, int currentNode, int prevNode, int& N) {
      for (int& node: graph[currentNode]) {
        if (node == prevNode) continue;
        int childrens = 1 + subtreeSizes[node];
        distances[node] = distances[currentNode] - childrens + (N - childrens);
        
        dfs2(graph, subtreeSizes, distances, node, currentNode, N);
      }
    }
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> graph = buildGraph(edges);
        vector<int> subtreeSizes(n, 0);
        vector<int> distances(n);
        int rootDistance = 0;
        dfsfill(graph, 0, 0, subtreeSizes, rootDistance, 0);
        distances[0] = rootDistance;
        dfs2(graph, subtreeSizes, distances, 0, -1, n);
        return distances;
    }
};