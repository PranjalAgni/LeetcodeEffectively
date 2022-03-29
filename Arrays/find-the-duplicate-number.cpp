// https://leetcode.com/problems/find-the-duplicate-number/

// Using elements as index as elements are always in range [1,N]
// N = length of the given input array
// Time: O(N) | Space: O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int N = nums.size();
        for (int idx = 0; idx < N; ++idx) {
          int eltIdx = abs(nums[idx]) - 1;
          if (nums[eltIdx] < 0) return abs(nums[idx]);
          nums[eltIdx] *= -1;
        }
      
        return -1;
    }
};