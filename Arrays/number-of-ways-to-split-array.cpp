// https://leetcode.com/problems/number-of-ways-to-split-array/
// Time: O(N) | Space: O(N)
// We can use prefix sum and suffix sum to solve this problem
class Solution {
private:
    vector<long long> getPrefixSum(vector<int>& nums) {
        int N = nums.size();
        vector<long long> prefixSum(N, 0);
        prefixSum[0] = nums[0];
        for (int idx = 1; idx < N; idx++) {
            prefixSum[idx] = (long long)(nums[idx] + prefixSum[idx - 1]);
        }
        
        return prefixSum;
    }

    vector<long long> getSuffixSum(vector<int>& nums) {
        int N = nums.size();
        vector<long long> suffixSum(N, 0);
        suffixSum[N - 1] = nums[N - 1];
        for (int idx = N - 2; idx >= 0; idx--) {
            suffixSum[idx] = (long long)(nums[idx] + suffixSum[idx + 1]);
        }
        return suffixSum;
    }
public:
    int waysToSplitArray(vector<int>& nums) {
        vector<long long> prefixSum = getPrefixSum(nums);
        vector<long long> suffixSum = getSuffixSum(nums);
        int N = nums.size();
        int count = 0;
        for (int idx = 0; idx < N - 1; idx++) {
            if (prefixSum[idx] >= suffixSum[idx + 1]) {
                count += 1;
            }
        }

        return count;
    }
};