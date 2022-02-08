// https://leetcode.com/problems/add-digits/

class Solution {
public:
    // Time: O(N) | Space: O(1)
    int addDigits(int num) {
        while (num > 9) {
          int sum = 0;
          while (num != 0) {
            sum += num % 10;
            num /= 10;
          }
          num = sum;
        }
      
        return num;
    }
};