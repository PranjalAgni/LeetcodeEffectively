// https://leetcode.com/problems/maximum-alternating-sum-of-squares/

// Time: O(N*logN) | Space: O(N)
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int N = nums.size();
        vector<long long> squaredNums(N, 0);
        for (int idx = 0; idx < N; idx++) {
            squaredNums[idx] = (long long)(nums[idx] * nums[idx]);
        }

        sort(squaredNums.begin(), squaredNums.end());
        long long answer = 0;

        int left = 0;
        int right = N - 1;

        while (left <= right) {
            if (left == right) {
                answer += squaredNums[right];
                right -= 1;
            }
            else {
                answer += squaredNums[right] - squaredNums[left];
                right -= 1;
                left += 1;
            }
        }

        return answer;
    }
};
