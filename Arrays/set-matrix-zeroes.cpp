// https://leetcode.com/problems/set-matrix-zeroes/?envType=daily-question&envId=2025-05-21

// Time: O(n^2) | Space: O(1)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<vector<int>> positions;
        
        // pre processing
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (matrix[row][col] == 0) {
                    positions.push_back({row, col});
                }
            }
        }

        // core logic
        for (vector<int> position: positions) {
            int row = position[0];
            int col = position[1];

            // set to zero horizontally
            for (int c = 0; c < cols; c++) {
                matrix[row][c] = 0;
            }

            // set to zero vertically
            for (int r = 0; r < rows; r++) {
                matrix[r][col] = 0;
            }
        }
    }
};