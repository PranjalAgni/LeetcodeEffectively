// https://leetcode.com/problems/single-number-iii/

// Solved with xor trick 
// Find the right most set bit
// And then check with each element in nums where the set bit is matching

// Time: O(N) | Space: O(1)
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int val = 0;
        for(int& num: nums) {
          val ^= num;
        }
          
        int mask = 0;
        if (val < 0) {
            unsigned int x = val;
            mask = x & -x;
        } else {
          mask = (val & -val);  
        }
        
        int first = 0;
        
        for (int& num: nums) {
          if (num & mask) {
            first ^= num;
          }
        }
      
        return {first, first ^ val};
    }
};