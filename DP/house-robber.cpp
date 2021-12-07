// https://leetcode.com/problems/house-robber/

class Solution {
public:
    // Time: O(N) | Space: O(N)
    int rob(vector<int>& nums) {
        int N = nums.size();
        if (N == 1) return nums[0];
        vector<int> robberDP(N, 0);
        robberDP[0] = nums[0];
        robberDP[1] = max(nums[0], nums[1]);
        for (int idx = 2; idx < N; idx++) {
          robberDP[idx] = max(robberDP[idx - 1], nums[idx] + robberDP[idx - 2]);
        }
        
        return max(robberDP[N - 1], robberDP[N - 2]);
    }
};
