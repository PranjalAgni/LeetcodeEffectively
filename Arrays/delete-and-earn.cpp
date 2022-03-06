// https://leetcode.com/problems/delete-and-earn/

class Solution {
public:
    // Time: O(N) | Space: O(1)
    int deleteAndEarn(vector<int>& nums) {
      int N = 10001;
      vector<int> values(N, 0);
      
      for (int num: nums) {
        values[num] += num;
      }
      
      int take = 0;
      int skip = 0;
      for (int idx = 0; idx < N; idx++) {
        int takei = skip + values[idx];
        int skipi = max(skip, take);
        take = takei;
        skip = skipi;
      }
      
      return max(take, skip);
    }
};