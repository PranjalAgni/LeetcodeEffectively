// https://leetcode.com/problems/fibonacci-number/

// Time: O(N) | Space: O(N)
// Space talen is from callstack
class Solution {
public:
    int fib(int n) {
      if (n == 0 || n == 1) return n;
      return fib(n - 1) + fib(n - 2);
    }
};