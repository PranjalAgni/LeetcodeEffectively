// https://leetcode.com/problems/subarray-product-less-than-k/

class Solution {
public:
    // Time: O(N) | Space: O(1)
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int N = nums.size();
        int left = 0;
        int right = 0;
        int prod = 1;
        int count = 0;
      
        while (right < N) {
          prod *= nums[right];
          if (prod < k) {
            count += 1;
          } else {
            while (prod >= k && left <= right) {
              prod = prod / nums[left];
              left += 1;
            }
            
            count += 1;
          }
          
          right += 1;
        }
      
        return count;
    }
};