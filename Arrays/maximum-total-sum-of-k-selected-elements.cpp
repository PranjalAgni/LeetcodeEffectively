// https://leetcode.com/contest/weekly-contest-508/problems/maximum-total-sum-of-k-selected-elements/

// Time: O(N) | Space: O(1)
class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(), nums.end());
        int N = nums.size();
        int pos = N - 1;
        int till = N - k;
        long long answer = 0;
        
        while (pos >= till) {
            if (mul > 0) {
                answer += (long long) mul * nums[pos];
                mul -= 1;
            } else {
                answer += (long long)nums[pos];
            }

            pos -= 1;
        }

        return answer;
    }
};©leetcode