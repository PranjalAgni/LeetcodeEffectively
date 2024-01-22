// https://leetcode.com/problems/set-mismatch/
class Solution {
public:
    // Time: O(N) | Space: O(1)
    vector<int> findErrorNums(vector<int>& nums) {
        int N = nums.size();
        int duplicateNumber = -1;
        int missingNumber = -1;
        for (int idx = 0; idx < N; idx++) {
          int realIdx = abs(nums[idx]) - 1;
          if(nums[realIdx] < 0) duplicateNumber = abs(nums[idx]);
          // marking this as visited
          else nums[realIdx] *= -1;
        }
        
        
        for (int idx = 0; idx < N; idx++) {
          if (nums[idx] > 0) {
            missingNumber = idx + 1;
            break;
          }
        }
      
        return {duplicateNumber, missingNumber};
    }
};

