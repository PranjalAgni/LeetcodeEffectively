// https://leetcode.com/problems/maximum-ascending-subarray-sum/

// Time: O(N) | Space: O(1)
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int N = nums.size();
        int answer = nums[0];
        int current = nums[0];
        for (int idx = 1; idx < N; idx++) {
            if (nums[idx] > nums[idx - 1]) {
                current += nums[idx];
            } else {
                answer = max(answer, current);
                current = nums[idx];
            }
        }

        answer = max(answer, current);
        return answer;
    }
};