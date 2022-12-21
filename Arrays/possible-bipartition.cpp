// https://leetcode.com/problems/possible-bipartition/

class Solution {
public:
    bool dfs(vector<vector<int>>& adj, vector<int>& groups, int v, int grpNum) {
      if (groups[v] == -1) groups[v] = grpNum;
      else return groups[v] == grpNum;
      
      for (int n: adj[v]) {
        if (!dfs(adj, groups, n, 1 - grpNum)) return false;
      }
      
      return true;
    }
  
    // Time: O(N) | Space: O(N)
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<int> groups(N, -1);
        vector<vector<int>> adjVec(N, vector<int>());
      
      
        for (vector<int>& p : dislikes) {
          adjVec[p[0] - 1].push_back(p[1] - 1);
          adjVec[p[1] - 1].push_back(p[0] - 1);
        }
      
        for (int i = 0; i < N; i++) {
          if (groups[i] == -1 && !dfs(adjVec, groups, i, 0)) return false;
        }
      
        return true;
    }
};

