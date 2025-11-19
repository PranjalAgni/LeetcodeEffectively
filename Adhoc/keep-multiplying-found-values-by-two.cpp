// https://leetcode.com/problems/keep-multiplying-found-values-by-two/?envType=daily-question&envId=2025-11-19

// Time: O(N) | Space: O(N)
// N = len(nums)
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_map<int, int> freqMap;
        for (int& num: nums) {
            freqMap[num] += 1;
        }

        while (freqMap[original] != 0) {
            original *= 2;
        }

        return original;
    }
};