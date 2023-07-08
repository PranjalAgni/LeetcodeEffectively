// https://leetcode.com/problems/minimum-size-subarray-sum/

// This solution uses sliding window

class Solution {
public:
    // Time: O(N) | Space: O(1)
    int minSubArrayLen(int target, vector<int>& nums) {
        int N = nums.size();
        int minimalLength = INT_MAX;
        int left = 0;
        int right = 0;
        int currentSum = 0;
        while (right < N) {
          currentSum += nums[right];
          
          while (currentSum >= target) {
            int currentLength = right - left + 1;
            minimalLength = min(minimalLength, currentLength);
            currentSum -= nums[left];
            left += 1;
          }
          
          right += 1;
        }
      
        return minimalLength == INT_MAX ? 0 : minimalLength;
    }
};