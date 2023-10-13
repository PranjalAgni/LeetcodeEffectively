// https://leetcode.com/problems/min-cost-climbing-stairs/
class Solution {
public:
    // Time: O(N) | Space: O(N)
    int minCostClimbingStairs(vector<int>& cost) {
        int N = cost.size();
        vector<int> dp(N, 0);
        dp[0] = cost[0];  
        dp[1] = cost[1];
        
        for (int idx = 2; idx < N; idx++) {
          dp[idx] = cost[idx] + min(dp[idx - 1], dp[idx - 2]);        
        }
      
        return min(dp[N - 1], dp[N - 2]);
    }
};