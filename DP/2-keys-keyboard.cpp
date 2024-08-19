// https://leetcode.com/problems/2-keys-keyboard/

// Time: O(N*N) | Space: O(N)
class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n + 1);
        for (int idx = 2; idx <= n; idx++) {
          dp[idx] = idx;
          for (int j = idx - 1; j > 1; j--) {
            if (idx % j == 0) {
              dp[idx] = dp[j] + (idx / j);
              break;
            }
          }
        }
      
        return dp[n];
    }
};
