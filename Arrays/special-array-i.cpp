// https://leetcode.com/problems/special-array-i/description/

// Time: O(N) | Space: O(1)
class Solution {
private:
    bool isValid(int a, int b) {
        return ((a % 2 == 0) && (b % 2 != 0)) || ((a % 2 != 0) && (b % 2 == 0));
    }
public:
    bool isArraySpecial(vector<int>& nums) {
        int N = nums.size();
        if (N == 1) return true;
        for (int idx = 1; idx < N; idx++) {
            if (!isValid(nums[idx - 1], nums[idx])) return false;
        }

        return true;
    }
};