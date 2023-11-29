// https://leetcode.com/problems/number-of-1-bits/

// More details about bit twiddling: https://stackoverflow.com/questions/109023/count-the-number-of-set-bits-in-a-32-bit-integer

// How it works?
/*
    n & (n - 1) drops the lowest set bit. It's a neat little bit trick.

    Let's use n = 00101100 as an example. This binary representation has three 1s.

    If n = 00101100, then n - 1 = 00101011, so n & (n - 1) = 00101100 & 00101011 = 00101000. Count = 1.
*/ 

// Time: O(1) | Space: O(1)
// Its constant time because max number of bits can be 32 only so maximum number of loop iterations will be 32 only
class Solution {
public:
    int hammingWeight(uint32_t n) {
      int cnt = 0;
      while(n > 0) {
        n &= n - 1;
        cnt += 1;
      }
      
      return cnt;
    }
};