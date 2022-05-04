// https://leetcode.com/problems/max-number-of-k-sum-pairs/

class Solution {
public:
    // Time: O(N*logN) | Space: O(1)
    int maxOperations(vector<int>& nums, int k) {
      int N = nums.size();
      int left = 0;
      int right = N - 1;
      sort(nums.begin(), nums.end());
      int answer = 0;
      while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == k) {
          answer += 1;
          left += 1;
          right -= 1;
        } else if (sum > k) {
          right -= 1;  
        } else {
          left += 1;
        }
      }
      
      return answer;
    }
};