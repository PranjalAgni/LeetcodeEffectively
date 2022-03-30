class Solution {
public:
    // Time: O(N + M) | Space: O(1)
    // N = rows
    // M = cols
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        int row = 0;
        int col = cols - 1;
        
        while (row < rows && col >= 0) {
          int current = matrix[row][col];
          if (current == target) return true;
          if (current > target) col -= 1;
          else row += 1;
        }
      
        return false;
    }
};