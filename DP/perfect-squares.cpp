// https://leetcode.com/problems/perfect-squares/

class Solution {
public:
    // Time: O(sqrt(N) * N) | Space: O(N)
    int numSquares(int n) {
      vector<int> dp(n + 1, INT_MAX);
      dp[0] = 0;
      int count = 1;
      int square = count * count;
      while (square <= n) {
        for (int num = square; num <= n; num++) {
          dp[num] = min(dp[num - square] + 1, dp[num]);
        }
        
        count += 1;
        square = count * count;
      }
      
      return dp[n];
    }
};
