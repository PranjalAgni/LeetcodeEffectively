// https://leetcode.com/problems/squares-of-a-sorted-array/?envType=daily-question&envId=2024-03-02

class Solution {
public:
    // Time: O(N*logN) | Space: O(1)
    vector<int> sortedSquares(vector<int>& nums) {
        int N = nums.size();
        for (int idx = 0; idx < N; idx++) {
          nums[idx] = nums[idx] * nums[idx];
        }
      
        sort(nums.begin(), nums.end());
        return nums;
    }
};