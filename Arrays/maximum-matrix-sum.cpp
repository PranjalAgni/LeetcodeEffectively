class Solution {
   public:
    // Time: O(rows * cols) | Space: O(1)
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int negativeCount = 0;
        long long sum = 0;
        int minNumber = INT_MAX;
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                int curr = matrix[row][col];
                if (curr < 0) negativeCount += 1;
                sum += abs(curr);
                minNumber = min(minNumber, abs(curr));
            }
        }

        return (negativeCount % 2 == 0) ? sum : sum - (2 * minNumber);
    }
};