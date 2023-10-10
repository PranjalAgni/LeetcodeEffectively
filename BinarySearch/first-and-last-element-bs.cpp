// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

// Currently wip solution
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int N = nums.size();
        int left = 0;
        int right = N - 1;
        int eltIdx = -1;
        while (left < right) {
          int mid = left + (right - left) / 2;
          if (nums[mid] == target) {
            eltIdx = mid;
            break;
          } else if (nums[mid] < target) {
            left = mid + 1;
          } else {
            right = mid - 1;
          }
        }
      
        if (eltIdx == -1) return {-1, -1};
          
        // find the left min
        int ansLeft = eltIdx;
        left = 0;
        right = eltIdx - 1;
      
        while (left <= right) {
          int mid = left + (right - left) / 2;
          if (nums[mid] == target) {
            ansLeft = min(ansLeft, mid);
            right = mid - 1;
          } else if (nums[mid] < target) {
            left = mid + 1;
          } else {
            right = mid - 1;
          }
        }
              
        // find the right max
        int ansRight = eltIdx;
        left = eltIdx + 1;
        right = N - 1;
        
        while (left <= right) {
          int mid = left + (right - left) / 2;
          if (nums[mid] == target) {
            ansRight = max(ansRight, mid);
          } else if (nums[mid] < target) {
            left = mid + 1;
          } else {
            right = mid - 1;
          }
        }
        
        return {ansLeft, ansRight};
        
    }
};