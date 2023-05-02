// https://leetcode.com/problems/sign-of-the-product-of-an-array/

class Solution {
public:
    // Time: O(N) | Space: O(1)
    int arraySign(vector<int>& nums) {
        int negativeSignsCount = 0;
        for (int& num: nums) {
          if (num == 0) return 0;
          if (num < 0) negativeSignsCount += 1;
        }
      
        return ((negativeSignsCount & 1) == 0) ? 1 : -1;
    }
};