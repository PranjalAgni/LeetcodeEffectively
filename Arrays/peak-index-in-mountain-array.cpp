// https://leetcode.com/problems/peak-index-in-a-mountain-array/

class Solution {
public:
    // Time: O(N) | Space: O(1)
    int peakIndexInMountainArray(vector<int>& arr) {
        int N = arr.size();
        for (int idx = 1; idx + 1 < N; idx++) {
          if (arr[idx] > arr[idx + 1]) return idx;
        }
      
        return -1;
    }
};