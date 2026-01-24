// https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/

// Time: O(N) | Space: O(1)
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int N = nums.size();
        int left = 0;
        int right = N - 1;
        int answer = INT_MIN;
        while (left < right) {
            int sum = nums[left] + nums[right];
            answer = max(answer, sum);
            left += 1;
            right -= 1;
        }

        return answer;
    }
};