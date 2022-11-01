// https://leetcode.com/problems/where-will-the-ball-fall/

class Solution {
private:
   int solve(vector<vector<int>>& grid, int row, int col, int& rows, int& cols) {
     if (row >= rows) return col;
     int neighbourCol = col + grid[row][col];
     if (neighbourCol < 0 || neighbourCol >= cols || grid[row][col] != grid[row][neighbourCol]) return -1;
     return solve(grid, row + 1, neighbourCol, rows, cols);
   }

public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<int> answer(cols);
      
        for (int col = 0; col < cols; col++) {
          answer[col] = solve(grid, 0, col, rows, cols);
        }
      
        return answer;
    }
};