// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

class Solution {
public:
    // Time: O(N) | Space: O(1)
    int findUnsortedSubarray(vector<int>& nums) {
        int N = nums.size();
        int max = nums[0];
        int end = -1;
      
        for (int idx = 1; idx < N; idx++) {
          if (max > nums[idx]) {
            end = idx;
          } else {
            max = nums[idx];
          }
        }
      
        int start = 0;
        int min = nums[N - 1];
        for (int idx = N - 2; idx >= 0; idx--) {
          if (min < nums[idx]) {
            start = idx;
          } else {
            min = nums[idx];
          }
        }
      
        return end - start + 1;
    }
};