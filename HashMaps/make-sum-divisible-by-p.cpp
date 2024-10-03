// https://leetcode.com/problems/make-sum-divisible-by-p/?envType=daily-question&envId=2024-10-03

// Currently inprogress
// Need to solve this using prefix sums
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int total = 0;
        int N = nums.size();
        for (int& num: nums) {
            total += num;
        }
        
        int left = 0;
        int right = N;
        int answer = 0;
        while (left < right) {
            if (total % p == 0) break;
            total -= nums[left];
            answer += 1;
            left += 1;
        }
        
        return (answer == 0) ? -1 : answer;
    }
};