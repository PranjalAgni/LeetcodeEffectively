// https://leetcode.com/problems/n-th-tribonacci-number/

// Memoization solution using dp
class Solution {
private:
    // Time: O(N) | Space: O(N)
    int tribonacciRec(int n, vector<int>& dp) {
        if (dp[n] != -1) return dp[n];
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;
        dp[n] = tribonacciRec(n - 1, dp) + tribonacciRec(n - 2, dp) + tribonacciRec(n - 3, dp);
        return dp[n];
    }
public:
    int tribonacci(int n) {
        vector<int> dp(n + 1, -1);
        return tribonacciRec(n, dp);
     }
};