// https://leetcode.com/problems/count-the-number-of-complete-components/

// Time: O(N + E) | Space: O(N)
class Solution {
  private:
      unordered_map<int, vector<int>> constructGraph(vector<vector<int>>& edges) {
          unordered_map<int, vector<int>> graph;
          for (vector<int>& edge: edges) {
              graph[edge[0]].push_back(edge[1]);
              graph[edge[1]].push_back(edge[0]);
          }
  
          return graph;
      }
  
      void dfs(unordered_map<int, vector<int>>& graph, vector<int>& visited, int node, vector<int>& vertexCovered) {
          if (visited[node] == 1) return;
          visited[node] = 1;
          vertexCovered.push_back(node);
  
          for (int& neighbour: graph[node]) {
              dfs(graph, visited, neighbour, vertexCovered);
          }
      }
  
      bool isComplete(unordered_map<int, vector<int>>& graph, vector<int>& vertexCovered) {
          int N = vertexCovered.size();
          for (int idx = 0; idx < N - 1; idx++) {
              int curr = vertexCovered[idx];
              vector<int> edges = graph[curr];
              for (int jdx = idx + 1; jdx < N; jdx++) {
                  int target = vertexCovered[jdx];
                  bool isFound = false;
                  for (int& e: edges) {
                      if (e == target) {
                          isFound = true;
                          break;
                      }
                  }
  
                  if (!isFound) return false;
              }
          }
  
          return true;
      }
  public:
      int countCompleteComponents(int N, vector<vector<int>>& edges) {
          // we need to construct a graph
          // dfs on graph 
          // count how many times we need to do the root dfs()
          // return the count
          unordered_map<int, vector<int>> graph = constructGraph(edges);
  
          vector<int> visited(N, 0);
          int answer = 0;
          for (int vertex = 0; vertex < N; vertex++) {
              vector<int> vertexCovered;
              if (visited[vertex] == 0) {
                  dfs(graph, visited, vertex, vertexCovered);
                  if (isComplete(graph, vertexCovered)) answer += 1;
              }
          }
  
          return answer;
      }
  };