// https://leetcode.com/problems/count-the-number-of-complete-components/

// Time: O(N + E) | Space: O(N)
// this solution uses set to check if direct edge exists later when checking for complete connected components
class Solution {
  private:
      unordered_map<int, unordered_set<int>> constructGraph(vector<vector<int>>& edges) {
          unordered_map<int, unordered_set<int>> graph;
          for (vector<int>& edge: edges) {
              graph[edge[0]].insert(edge[1]);
              graph[edge[1]].insert(edge[0]);
          }
  
          return graph;
      }
  
      void dfs(unordered_map<int, unordered_set<int>>& graph, vector<int>& visited, int node, vector<int>& vertexCovered) {
          if (visited[node] == 1) return;
          visited[node] = 1;
          vertexCovered.push_back(node);
  
          for (auto it = graph[node].begin(); it != graph[node].end(); it++) {
              dfs(graph, visited, *it, vertexCovered);
          }
      }
  
      bool isComplete(unordered_map<int, unordered_set<int>>& graph, vector<int>& vertexCovered) {
          int N = vertexCovered.size();
          for (int idx = 0; idx < N - 1; idx++) {
              int curr = vertexCovered[idx];
              unordered_set<int> edges = graph[curr];
              for (int jdx = idx + 1; jdx < N; jdx++) {
                  int target = vertexCovered[jdx];
                  if (edges.find(target) == edges.end()) return false;
              }
          }
  
          return true;
      }
  public:
      int countCompleteComponents(int N, vector<vector<int>>& edges) {
          unordered_map<int, unordered_set<int>> graph = constructGraph(edges);
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