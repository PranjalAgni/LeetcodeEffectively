// https://leetcode.com/problems/sort-array-by-parity/

class Solution {
public:
    // Time: O(N) | Space: O(1)
    vector<int> sortArrayByParity(vector<int>& nums) {
        int N = nums.size();
        int evenIndex = 0;
        int oddIndex = N - 1;
        while (evenIndex <= oddIndex) {
          int eltA = nums[evenIndex];
          int eltB = nums[oddIndex];
          if (eltA % 2 != 0 && eltB % 2 == 0) {
            swap(nums[evenIndex], nums[oddIndex]);
            evenIndex += 1;
            oddIndex -= 1;
          } else if (eltA % 2 == 0) {
            evenIndex += 1;
          } else if (eltB % 2 != 0) {
            oddIndex -= 1;
          }
        }
      
        return nums;
    }
};