// https://leetcode.com/problems/maximum-difference-between-increasing-elements/description/?envType=daily-question&envId=2025-06-17

// Good intro problem to understand the concept of prefix and suffix arrays
// Time: O(N) | Space: O(N)

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int N = nums.size();
        vector<int> prefixMin(N);
        vector<int> suffixMax(N);
        prefixMin[0] = nums[0];
        suffixMax[N - 1] = nums[N - 1];

        for (int idx = 1; idx < N; idx++) {
            prefixMin[idx] = min(prefixMin[idx - 1], nums[idx]);
        }

        for (int idx = N - 2; idx >= 0; idx--) {
            suffixMax[idx] = max(suffixMax[idx + 1], nums[idx]);
        }

        int ans = 0;
        for (int idx = 0; idx < N; idx++) {
            ans = max(ans, suffixMax[idx] - prefixMin[idx]);
        }

        return ans == 0 ? -1 : ans;
    }
};