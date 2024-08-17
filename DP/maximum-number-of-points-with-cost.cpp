// https://leetcode.com/problems/maximum-number-of-points-with-cost/

// This is a very nice problem demonstrating the use of precomputation technique
// prefix max and suffix max and using it to calculate the dp table

// Idea:
// For every cell in the row we need to know the max value of the cell just above it
// this can be pre-computed using the prefix/suffix max'es
// now dp[row][col] = points[row][col] + max(prefix[col], suffix[col]) 

// Note: Solved this using recursion + memoization first but got TLE
// https://leetcode.com/submissions/detail/1358748403/


// Time: O(rows * (cols + cols + cols)) | Space: O(rows*cols)
class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int rows = points.size();
        int cols = points[0].size();
      
        vector<vector<long long>> dp(rows, vector<long long>(cols, 0));
      
        // init dp base row
        for (int col = 0; col < cols; col++) {
            dp[0][col] = points[0][col];
        }
      
        for (int row = 1; row < rows; row++) {
          vector<long long> prefix(cols, 0);
          vector<long long> suffix(cols, 0);
          // compute prefix and suffix
          prefix[0] = dp[row - 1][0];
          suffix[cols - 1] = dp[row - 1][cols - 1];
          
          for (int col = 1; col < cols; col++) {
            prefix[col] = max<long long int>(prefix[col - 1] - 1, dp[row - 1][col]);
          }
          
          for (int col = cols - 2; col >= 0; col--) {
            suffix[col] = max<long long int>(suffix[col + 1] - 1, dp[row - 1][col]);
          }
          
          for (int col = 0; col < cols; col++) {
            dp[row][col] = max(prefix[col], suffix[col]) + points[row][col];
          }
        }
      
        return *max_element(dp[rows - 1].begin(), dp[rows - 1].end());        
    }
};
