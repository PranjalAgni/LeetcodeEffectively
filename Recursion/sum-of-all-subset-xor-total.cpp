// https://leetcode.com/problems/sum-of-all-subset-xor-totals/

// Time: O(2^N) | Space: O(N)
class Solution {
private:
    int recurse(vector<int>& nums, int idx, int current) {
      if (idx == nums.size()) {
        return current;
      }
      
      return recurse(nums, idx + 1, current ^ nums[idx]) + recurse(nums, idx + 1, current);
    }
public:
    int subsetXORSum(vector<int>& nums) {
        return recurse(nums, 0, 0);
    }
};