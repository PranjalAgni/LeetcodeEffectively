// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/

// This is a very nice DFS + DP problem
class Solution {
private:
    bool isValid(int row, int col, int& rows, int& cols) {
      if (row < 0 || row >= rows || col < 0 || col >= cols) return false;
      return true;
    }
    
    // Implementing DFS
    // Time: O(rows * cols) | Space: O(rows * cols)
    int dfs(vector<vector<int>>& matrix, int row, int col, int& rows, int& cols, vector<vector<int>>& dp) {
      if (dp[row][col]) return dp[row][col];
      vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
      dp[row][col] = 1;
      for (vector<int>& dir: directions) {
        int nextRow = row + dir[0];
        int nextCol = col + dir[1];
        if (!isValid(nextRow, nextCol, rows, cols)) continue;
        if (matrix[nextRow][nextCol] <= matrix[row][col]) continue;
        int lengthValue = 1 + dfs(matrix, nextRow, nextCol, rows, cols, dp);
        dp[row][col] = max(dp[row][col], lengthValue);
      }
      
      return dp[row][col];
    }
public:
    // Time: O(rows * cols) | Space: O(rows * cols)
    int longestIncreasingPath(vector<vector<int>>& matrix) {
      int rows = matrix.size();
      int cols = matrix[0].size();
      vector<vector<int>> dp(rows, vector<int>(cols, 0));
      int maxLength = 0;
      for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
          maxLength = max(maxLength, dfs(matrix, row, col, rows, cols, dp));
        }
      }
      
      return maxLength;
    }
};