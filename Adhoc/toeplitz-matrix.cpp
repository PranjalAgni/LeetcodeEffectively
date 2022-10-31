class Solution {
public:
    // Time: O(rows * cols) | Space: O(rows * cols)
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        if (rows == 1 || cols == 1) return true;
        vector<vector<int>> visited(rows, vector<int>(cols, 0));
      
        for (int row = 0; row < rows; row++) {
          for (int col = 0; col < cols; col++) {
            if (!visited[row][col]) {
              int val = matrix[row][col];
              int trow = row;
              int tcol = col;
              while (trow < rows && tcol < cols) {
                visited[trow][tcol] = 1;
                if (val != matrix[trow][tcol]) return false;
                trow += 1;
                tcol += 1;
              }
            }
          }
        }
      
        return true;
    }
};