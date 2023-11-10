// https://leetcode.com/problems/restore-the-array-from-adjacent-pairs/

class Solution {
private:
    void constructGraph(unordered_map<int, list<int>>& graph, vector<vector<int>>& adjacentPairs) {
      for (vector<int>& pair: adjacentPairs) {
        graph[pair[0]].push_back(pair[1]);
        graph[pair[1]].push_back(pair[0]);
      }
    }
  
    int findStartingPoint(unordered_map<int, list<int>>& graph) {
      for (auto& node: graph) {
        if (node.second.size() == 1) return node.first;
      }
      
      // will not be possible in the given input
      return -1;
    }
public:
    // Time: O(N) | Space: O(N)
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        int N = adjacentPairs.size();
        unordered_map<int, list<int>> graph;
        constructGraph(graph, adjacentPairs);
        unordered_map<int, int> visitedMap;
        vector<int> answer;
      
      
        int startingNode = findStartingPoint(graph);
        while (!visitedMap[startingNode]) {
          visitedMap[startingNode] = 1;
          answer.push_back(startingNode);
          list<int> currentNodes = graph[startingNode];
          
          if (currentNodes.size() == 0) break;
          
          int nextNode;
          
          while(currentNodes.size() > 0) {
            nextNode = currentNodes.front();
            currentNodes.pop_front();
            if (!visitedMap[nextNode]) break;
          }
          
          startingNode = nextNode;
        }
      
        return answer;
    }
};