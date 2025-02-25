// https://leetcode.com/problems/most-profitable-path-in-a-tree/

// Time: O(V + E) | Space: O(V)
// V = number of vertices, E = number of edges
class Solution {
  private:
      bool dfs(unordered_map<int, vector<int>>& graph, int src, int dest, int time, unordered_map<int, int>& timeToReach, unordered_map<int, bool>& visited) {
          if (visited[src]) return false;
          visited[src] = true;
  
          timeToReach[src] = time;
  
          // reached the target node
          if (src == dest) return true;
  
          // traverse in graph to reach the target node
          for (int& neighbour: graph[src]) {
              if (!visited[neighbour]) {
                  bool found = dfs(graph, neighbour, dest, time + 1, timeToReach, visited);
                  if (found) return true;
              }
          }
  
          timeToReach.erase(src);
          return false;
      }
  public:
      int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
          unordered_map<int, vector<int>> graph;
          unordered_map<int, int> timeToReach;
          unordered_map<int, bool> visited;
  
          // construct graph
          for (vector<int>& edge: edges) {
              graph[edge[0]].push_back(edge[1]);
              graph[edge[1]].push_back(edge[0]);
          }
          
          // find the path for bob to reach node 0
          dfs(graph, bob, 0, 0, timeToReach, visited);
          
          // reset the visited map
          visited.clear();
          queue<vector<int>> q;
          
          // we have {alicePosition, timeTakenToReach, collectedAmount}
          q.push({0, 0, 0});
          int answer = INT_MIN;
          while (!q.empty()) {
              vector<int> details = q.front();
              q.pop();
  
              int alicePos = details[0];
              int time = details[1];
              int amountCollected = details[2];
  
              if (visited[alicePos]) continue;
              visited[alicePos] = true;
              
              if (timeToReach.find(alicePos) == timeToReach.end()) {
                  amountCollected += amount[alicePos];
              } else {
                  int timeTakenForBob = timeToReach[alicePos];
                  if (time < timeTakenForBob) {
                      amountCollected += amount[alicePos];
                  } else if (time == timeTakenForBob) {
                      amountCollected += (amount[alicePos] / 2);
                  }
              }
  
              vector<int> neighbour = graph[alicePos];
              // leaf node
              if (neighbour.size() == 1 && alicePos != 0) {
                  answer = max(answer, amountCollected);
              }
  
              for (int& node: neighbour) {
                  q.push({node, time + 1, amountCollected});
              }
          }
  
          return answer; 
      }
  };