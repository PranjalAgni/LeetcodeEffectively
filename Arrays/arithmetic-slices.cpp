// https://leetcode.com/problems/arithmetic-slices/

// Nice question and clever solution

class Solution {
public:
    // Time: O(N) | Space: O(1)
    int numberOfArithmeticSlices(vector<int>& nums) {
      int totalSlices = 0;
      int currentSlice = 0;
      int N = nums.size();
      for (int idx = 2; idx < N; idx++) {
        if (nums[idx] - nums[idx - 1] == nums[idx - 1] - nums[idx - 2]) {
          currentSlice += 1;
          totalSlices += currentSlice;
        } else {
          currentSlice = 0;
        }
      }
      
      return totalSlices;
    }
};