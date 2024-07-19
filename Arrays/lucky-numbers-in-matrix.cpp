// https://leetcode.com/problems/lucky-numbers-in-a-matrix/

// Time: O(rows*cols) | Space: O(rows)
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> rowMin(rows);
      
        vector<int> colMax(cols);
      
        for (int row = 0; row < rows; row++) {
          int val = INT_MAX;
          for (int col = 0; col < cols; col++) {
            val = min(val, matrix[row][col]);
          }
          
          rowMin[row] = val;
        }
      
        for (int col = 0; col < cols; col++) {
          int val = INT_MIN;
          for (int row = 0; row < rows; row++) {
            val = max(val, matrix[row][col]);
          }
          
          colMax[col] = val;
        }
      
        for (int row = 0; row < rows; row++) {
          for (int col = 0; col < cols; col++) {
            int val = matrix[row][col];
            if (val == rowMin[row] && val == colMax[col]) return {val}; 
          }
        }
      
        return {};
    }
};