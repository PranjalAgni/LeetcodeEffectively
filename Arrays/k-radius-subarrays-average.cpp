// https://leetcode.com/contest/weekly-contest-269/problems/k-radius-subarray-averages/

class Solution {
   public:
    // Time: O(N - k) | Space: O(N)
    vector<int> getAverages(vector<int>& nums, int k) {
        if (k == 0) return nums;
        int N = nums.size();
        vector<long long> prefixSum(N);
        prefixSum[0] = nums[0];
        for (int idx = 1; idx < N; idx++) {
            prefixSum[idx] = prefixSum[idx - 1] + nums[idx];
        }

        vector<int> kRadiusAverage(N, -1);

        long long elements = 2 * k + 1;
        for (int idx = k; idx < N - k; idx++) {
            long long sum = prefixSum[idx + k];
            if ((idx - k - 1) >= 0) sum -= prefixSum[idx - k - 1];
            kRadiusAverage[idx] = sum / elements;
        }

        return kRadiusAverage;
    }
};