// https://leetcode.com/problems/missing-number/

// Simple solution based on sum of n numbers (AP)
class Solution {
public:
    // Time: O(N) | Space: O(1)
    int missingNumber(vector<int>& nums) {
        int N = nums.size();
        int sum = (N * (N + 1)) / 2;
        int total = 0;
        for (int num: nums) total += num;
        return sum - total;
    }
};