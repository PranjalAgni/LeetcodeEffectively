// https://leetcode.com/problems/subsets

// Recursive solution
// Time: O(N*N) | Space: O(N)
class Solution {
private:
    void computeSubsetRecursive(vector<int>& nums, int idx, int& N, vector<int>& current, vector<vector<int>>& answer) {
      answer.push_back(current);
      for (int pos = idx; pos < N; pos++) {
        current.push_back(nums[pos]);
        computeSubsetRecursive(nums, pos + 1, N, current, answer);
        current.pop_back();
      }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
      vector<vector<int>> answer;
      vector<int> current;
      int N = nums.size();
      computeSubsetRecursive(nums, 0, N, current, answer);
      return answer;
    }
};