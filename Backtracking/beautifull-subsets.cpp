// https://leetcode.com/problems/the-number-of-beautiful-subsets

// Time: O(2^N + N^2) | Space: O(N)
class Solution {
private:
    int dfs(vector<int>& nums, unordered_map<int, int>& freqMap, int idx, int& k) {
      if (idx == nums.size()) return 1;
      int taken = 0;
      if (!freqMap[nums[idx] - k] && !freqMap[nums[idx] + k]) {
        freqMap[nums[idx]] += 1;
        taken = dfs(nums, freqMap, idx + 1, k);
        freqMap[nums[idx]] -= 1;
      }
      
      int nottaken = dfs(nums, freqMap, idx + 1, k);
      return taken + nottaken;
      
    }
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        int ans = dfs(nums, freqMap, 0, k);
        return ans - 1;
    }
};