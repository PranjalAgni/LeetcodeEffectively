// https://leetcode.com/problems/where-will-the-ball-fall/

class Solution {
public:
    // Time: O(cols*rows) | Space: O(cols)
    vector<int> findBall(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<int> answer(cols);
      
        for (int ballId = 0; ballId < cols; ballId++) {
          int row = 0;
          int col = ballId;
          for (row = 0; row < rows; row++) {
            int neighbourCol = col + grid[row][col];
            if (neighbourCol < 0 || neighbourCol >= cols || grid[row][col] != grid[row][neighbourCol]) {
              col = -1;
              break;
            }
            
            col = neighbourCol;
          }
          
          answer[ballId] = col;
        }
      
        return answer;
    }
};