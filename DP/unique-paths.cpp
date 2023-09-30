// https://leetcode.com/problems/unique-paths/

// Nice beginner DP problem
class Solution {
public:
    // Time: O(m * n) | Space: O(m * n)
    int uniquePaths(int m, int n) {
       int rows = m;
       int cols = n;
       vector<vector<int>> dp(rows, vector<int>(cols));
      
       // in the 1st row and col we can go only in 1 way
       for (int col = 0; col < n; col++) {
         dp[0][col] = 1;
       }
      
       for (int row = 0; row < m; row++) {
         dp[row][0] = 1;
       } 
      
       for (int row = 1; row < m; row++) {
         for (int col = 1; col < n; col++) {
           dp[row][col] = dp[row - 1][col] + dp[row][col - 1];
         }
       }
      
       return dp[m - 1][n - 1];
    }
};