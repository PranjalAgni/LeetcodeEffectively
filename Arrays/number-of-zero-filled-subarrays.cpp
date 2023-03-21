// https://leetcode.com/problems/number-of-zero-filled-subarrays/

class Solution {
private:
    // Time: O(1) | Space: O(1)
    long long numSubarrays(long long count) {
      return ((count) * (count + 1)) / 2;
    }
public:
    // Time: O(N) | Space: O(1)
    long long zeroFilledSubarray(vector<int>& nums) {
       int N = nums.size();
       int start = 0;  
       long long count = 0;
       long long answer = 0; 
       while (start < N) {
         if (nums[start] == 0) count += 1;
         else {
           answer += numSubarrays(count);
           count = 0;
         }
         start += 1;
       }
      
       if (count != 0) answer += numSubarrays(count);
       return answer;
    }
};