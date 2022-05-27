// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/

class Solution {
// Time: O(N) | Space: O(1)
public:
    int numberOfSteps(int num) {
      int steps = 0;
      while (num != 0) {
        if (num % 2 == 0) {
          num = num / 2;
        } else {
          num -= 1;
        }
        
        steps += 1;
      }
      
      return steps;
    }
};

