// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

// Currently wip solution
class Solution {
private:
    int binarySearch(vector<int>& nums, int left, int right, int& target, int& start, int& end) {
      if (left > right) return -1;
      int mid = left + (right - left) / 2;
      if (nums[mid] == target) {
        int a = binarySearch(nums, left, mid - 1, target, start, end);
        int b = binarySearch(nums, mid + 1, right, target, start, end);
        cout << "Trying start = " << a << endl;
        if (a != -1) start = min(start, a);
        cout << "Trying end = " << b << endl;
        if (b != -1) end = max(end, b);
        return mid;
      } else if (nums[mid] < target) {
        return binarySearch(nums, mid + 1, right, target, start, end);
      } else {
        return binarySearch(nums, left, mid - 1, target, start, end);
      }
      
      return -1;
    }
public:
    // Time: O(logN) | Space: O(1)
    vector<int> searchRange(vector<int>& nums, int target) {
        int N = nums.size();
        int left = 0;
        int right = N - 1;
        int start = INT_MAX;
        int end = INT_MIN;
        binarySearch(nums, left, right, target, start, end);
        if (start == INT_MAX) start = -1;
        if (end == INT_MIN) end = -1;
        return {start, end};
    }
};