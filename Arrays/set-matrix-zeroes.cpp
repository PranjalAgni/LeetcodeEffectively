https://leetcode.com/problems/set-matrix-zeroes/?envType=daily-question&envId=2025-05-21
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<vector<int>> positions;
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (matrix[row][col] == 0) {
                    positions.push_back({row, col});
                }
            }
        }
    }
};