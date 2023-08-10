// https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int N = nums.size();
        int left = 0;
        int right = N - 1;
        
        // find lowest element first
        while (left < right) {
          int mid = left + (right - left) / 2;
          if (nums[mid] > nums[right]) {
            left = mid + 1;
          } else {
            right = mid;
          }
        }
        
        int rotation = left;
        left = 0;
        right = N - 1;
        
        // real binary search to find the index
        while (left <= right) {
          int mid = (left + right) / 2;
          int realmid = (mid + rotation) % N;
          if (nums[realmid] == target) {
            return realmid;
          }
          else if (nums[realmid] < target) {
            left = mid + 1; 
          } else {
            right = mid - 1;
          }
        }
      
        return -1;
    }
};