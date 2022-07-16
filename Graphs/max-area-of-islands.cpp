// https://leetcode.com/problems/max-area-of-island/

class Solution {
private:
    bool isValidCell(int currRow, int currCol, int& rows, int& cols) {
      return currRow >= 0 && currRow < rows && currCol >= 0 && currCol < cols;
    }
  
    void dfs(vector<vector<int>>& grid, int currRow, int currCol, int& rows, int& cols, int& currentArea) {
      if (grid[currRow][currCol] == 0) return;
      currentArea += 1;
      grid[currRow][currCol] = 0;
      vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
      
      for (vector<int>& dir: directions) {
        int nextRow = currRow + dir[0];
        int nextCol = currCol + dir[1];
        if (isValidCell(nextRow, nextCol, rows, cols) && grid[nextRow][nextCol] == 1) {
          dfs(grid, nextRow, nextCol, rows, cols, currentArea);
        }
      }
    }
public:
    // Time: O(rows * cols) | Space: O(1)
    // 1 <= rows, cols <= 50
    // not considering the space taken by the call stack
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int maxArea = 0;
        for (int row = 0; row < rows; row++) {
          int cols = grid[row].size();
          for (int col = 0; col < cols; col++) {
            if (grid[row][col] == 1) {
              int currentArea = 0;
              dfs(grid, row, col, rows, cols, currentArea);
              maxArea = max(currentArea, maxArea);
            } 
          }
        }
      
        return maxArea;
    }
};
