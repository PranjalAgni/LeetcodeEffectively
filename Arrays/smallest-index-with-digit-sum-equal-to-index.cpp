// https://leetcode.com/problems/smallest-index-with-digit-sum-equal-to-index/

// Time: O(N) | Space: O(1)
class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int N = nums.size();
        for (int idx = 0; idx < N; idx++) {
            int sum = 0;
            int elt = nums[idx];
            while (elt != 0) {
                sum = sum + (elt % 10);
                elt = elt / 10;
            }

            if (idx == sum) return idx;
        }

        return -1;
    }
};