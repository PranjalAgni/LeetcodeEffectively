// https://leetcode.com/problems/minimum-positive-sum-subarray/

// TC: O(N*N) | Space: O(N)
class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int N = nums.size();
        vector<int> prefixSum(N + 1, 0);

        for (int idx = 0; idx < N; idx++) {
            prefixSum[idx + 1] = prefixSum[idx] + nums[idx];
        }

        int answer = INT_MAX;
        for (int len = l; len <= r; len++) {
            for (int idx = 0; idx + len <= N; idx++) {
                int sum = prefixSum[idx + len] - prefixSum[idx];
                if (sum > 0) {
                    answer = min(answer, sum);
                }
            }
        }

        return answer == INT_MAX ? -1 : answer;

    }
};