// https://leetcode.com/problems/ugly-number-ii/

// Time: O(N) | Space: O(N)
// N = nth number to find
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> uglyNums(n);
        uglyNums[0] = 1;
      
        int t2 = 0;
        int t3 = 0;
        int t5 = 0;
      
        for (int idx = 1; idx < n; idx++) {
          int val = min({uglyNums[t2] * 2, uglyNums[t3] * 3, uglyNums[t5] * 5});
          uglyNums[idx] = val;
          if (uglyNums[t2] * 2 == val) t2 += 1;
          if (uglyNums[t3] * 3 == val) t3 += 1;
          if (uglyNums[t5] * 5 == val) t5 += 1;
        }
      
      
        return uglyNums[n - 1];
    }
};
