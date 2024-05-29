// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/

// Time: O(N) | Space: O(1)
// Things to know here:
// 1.If the last digit of a binary number is 1, the number is odd; if it’s 0, the number is even.
// 2. Removing the least significant bit (rightmost bit) means dividing the binary number by 2
// 3. Adding to binary number means adding 1 bit to LSB and then performing carry operation
// Reference: https://homepages.math.uic.edu/~scole3/mcs260_fall2011/binary.pdf

class Solution {
public:
    int numSteps(string s) {
      int N = s.length();
      int steps = 0;
      int carry = 0;
      for (int idx = N - 1; idx >= 0; idx--) {
        
        // carryover logic from last step
        if (carry) {
          if (s[idx] == '1') s[idx] = '0';
          else {
            s[idx] = '1';
            carry = 0;
          }
        }
        
        if (s[idx] == '0') {
          // this means number is even as least significant bit is 0
          // so we divide which means removing the rightmost bit
          steps += 1;
        } else {
          if (idx != 0) {
            carry = 1;
            // one for making it even and dividing by 2
            // and one for current step
            steps += 2;
          }
        }
      }
      
      return steps;
    }
};