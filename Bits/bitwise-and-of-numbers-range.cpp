// https://leetcode.com/problems/bitwise-and-of-numbers-range/

class Solution {
public:
    // Time: O(N) | Space: O(1)
    int rangeBitwiseAnd(int left, int right) {
        while(right > left) {
          right &= (right - 1);
        }
      
        return right;
    }
};