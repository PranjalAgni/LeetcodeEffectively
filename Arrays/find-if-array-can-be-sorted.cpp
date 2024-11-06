// https://leetcode.com/problems/find-if-array-can-be-sorted/submissions/

// Time: O(k*N) | Space: O(1)
class Solution {
private:
    int sortWithSwaps(vector<int>& nums) {
        int N = nums.size();
        int count = 0;
        for (int idx = 1; idx < N; idx++) {
            if (nums[idx - 1] > nums[idx]) {
                int a = __builtin_popcount(nums[idx - 1]);
                int b = __builtin_popcount(nums[idx]);
                if (a != b) return -1;
                swap(nums[idx - 1], nums[idx]);
                count += 1;
            }
        }
        
        return count;
    }
public:
    bool canSortArray(vector<int>& nums) {
        int N = nums.size();
        int iters = 1;
        int swaps = sortWithSwaps(nums);
        if (swaps == -1) return false;
        if (swaps == 0) return true;
        while (swaps > 0) {
            swaps = sortWithSwaps(nums);
            iters += 1;
            if (swaps == -1) return false;
        }
        
        return true;
    }
};
