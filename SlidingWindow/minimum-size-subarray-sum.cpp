// https://leetcode.com/problems/minimum-size-subarray-sum/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int N = nums.size();
        int minimalLength = INT_MAX;
        int left = 0;
        int right = 0;
        int currentSum = 0;
        while (right < N) {
          currentSum += nums[right];
          if (currentSum == target) {
            int currentLength = right - left + 1;
            minimalLength = min(minimalLength, currentLength);
          }
          if (currentSum > target) {
            // shrink the window
          }
          right += 1;
        }
    }
};