// https://leetcode.com/problems/longest-increasing-subsequence/

// Nice DP problem
class Solution {
public:
    // Time: O(N) | Space: O(N)
    int lengthOfLIS(vector<int>& nums) {
        int N = nums.size();
        vector<int> dp(N, 1);
        int answer = 1;
        for (int idx = 1; idx < N; idx++) {
            int count = 0;
            for (int jdx = 0; jdx < idx; jdx++) {
                if (nums[idx] > nums[jdx]) {
                    dp[idx] = max(dp[idx], dp[jdx] + 1);
                }
            }
            
            answer = max(answer, dp[idx]);
        }
        
        return answer;
    }
};