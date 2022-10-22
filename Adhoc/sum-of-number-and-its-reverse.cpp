// https://leetcode.com/contest/weekly-contest-315/problems/sum-of-number-and-its-reverse/

class Solution {
private:
    int getReverseNum(int num) {
      int reversedNum = 0;
      while (num != 0) {
        reversedNum = reversedNum * 10 + num % 10;
        num /= 10;
      }
      
      return reversedNum;
    }
public:
    // Time: O(N) | Space: O(N)
    // N = 1..num
    bool sumOfNumberAndReverse(int num) {
        if (num == 0) return true;
        for (int n = 1; n < num; n++) {
            int reverseN = getReverseNum(n);
            if (n + reverseN == num) return true;
        }
      
        return false;
    }
};