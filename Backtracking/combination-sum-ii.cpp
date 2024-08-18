// https://leetcode.com/problems/combination-sum-ii/

// Time: O(2^N) | Space: O(N)
class Solution {
private:
    void solve(vector<int>& candidates, int& N, int idx, int sum, int target, vector<int>& combination, vector<vector<int>>& result) {
      if (target == sum) {
        result.push_back(combination);
        return;
      }
      
      if (sum > target) return;
      
      for (int c = idx; c < N; c++) {
        if (c != idx && candidates[c] == candidates[c - 1]) {
          continue;
        }
        sum += candidates[c];
        combination.push_back(candidates[c]);
        solve(candidates, N, c + 1, sum, target, combination, result);
        sum -= candidates[c];
        combination.pop_back();
      }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int N = candidates.size();
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> res;
        solve(candidates, N, 0, 0, target, res, result);
        return result;
    }
};