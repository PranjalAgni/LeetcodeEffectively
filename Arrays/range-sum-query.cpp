// https://leetcode.com/problems/range-sum-query-immutable/

class NumArray {
   public:
    vector<int> prefixSum;
    int N;
    NumArray(vector<int>& nums) {
        N = nums.size();
        prefixSum = vector<int>(N);
        prefixSum[0] = nums[0];
        for (int idx = 1; idx < N; idx++) {
            prefixSum[idx] = prefixSum[idx - 1] + nums[idx];
        }
    }

    // Time: O(1) | Space: O(N)
    int sumRange(int left, int right) {
        int answer = prefixSum[right];
        if (left - 1 >= 0) answer -= prefixSum[left - 1];
        return answer;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */