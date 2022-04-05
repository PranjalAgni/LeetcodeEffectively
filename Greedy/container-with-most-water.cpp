// https://leetcode.com/problems/container-with-most-water/

class Solution {
public:
    // Time: O(N) | Space: O(1)
    int maxArea(vector<int>& height) {
        int N = height.size();
        int start = 0;
        int end = N - 1;
        int ans = INT_MIN;
      
        while (start < end) {
          int width = end - start;
          int minTowerHeight = min(height[start], height[end]);
          ans = max(ans, width * minTowerHeight);
          if (height[start] < height[end]) {
            start += 1;
          } else {
            end -= 1;
          }
        }
      
        return ans;
    }
};