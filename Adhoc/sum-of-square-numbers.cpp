// https://leetcode.com/problems/sum-of-square-numbers/submissions/

class Solution {
public:
    bool judgeSquareSum(int c) {
        for (long long a = 0; a * a <= c; a++) {
          long long a_squared = a * a;
          long long b_squared = (long long)(c - a_squared);
          long long b = sqrt(b_squared);
          if ((b * b) == b_squared) return true;
        }
        return false;
    }
};