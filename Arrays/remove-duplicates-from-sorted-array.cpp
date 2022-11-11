// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
    // Time: O(N) | Space: O(1)
    int removeDuplicates(vector<int>& nums) {
        int N = nums.size();
        if (N == 0) return 0;
        int pos = 0;
      
        for (int idx = 1; idx < N; idx++) {
          if (nums[idx] != nums[pos]) {
            pos += 1;
            nums[pos] = nums[idx];            
          }
        }
            
        return pos + 1;
    }
};