// https://leetcode.com/problems/triangle/

class Solution {
private:
  int findMinimumSum(vector<vector<int>>& triangle, int currRow, int currCol, int& rows, vector<vector<int>>& dp) {
    if (currRow == rows - 1) return triangle[currRow][currCol];
    if (dp[currRow][currCol] != -1) return dp[currRow][currCol];
    int cols = triangle[currRow].size();
    int pathA = triangle[currRow][currCol] + findMinimumSum(triangle, currRow + 1, currCol, rows, dp);
    
    int pathB = triangle[currRow][currCol] + findMinimumSum(triangle, currRow + 1, currCol + 1, rows, dp);
    
    dp[currRow][currCol] = min(pathA, pathB);
    return dp[currRow][currCol];

  }
public:
    // Time: O(rows) | Space: O(rows * rows)
    // rows = number of rows in the triangle grid
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size();
        vector<vector<int>> dp(rows, vector<int>(rows, -1));
        return findMinimumSum(triangle, 0, 0, rows, dp);
    }
};