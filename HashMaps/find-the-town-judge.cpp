// https://leetcode.com/problems/find-the-town-judge/

class Solution {
public:
    // Time: O(N) | Space: O(N)
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int, vector<int>> trustMap;
        unordered_map<int, bool> isTrustSomeoneMap;
        
        for (vector<int>& t: trust) {
          trustMap[t[1]].push_back(t[0]);
          isTrustSomeoneMap[t[0]] = true;
        }
      
        for (int idx = 1; idx <= n; idx++) {
          vector<int> peopleTrust = trustMap[idx];
          if (!isTrustSomeoneMap[idx] && peopleTrust.size() == n - 1) return idx;
        }
      
        return -1;
    }
};