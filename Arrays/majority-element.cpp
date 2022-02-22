// https://leetcode.com/problems/majority-element/

// This solution I learn't in my college days 
// from the "Cracking the coding interview" book

class Solution {
public:
    // Time: O(N) | Space: O(1)
    int majorityElement(vector<int>& nums) {
        int freq = 1;
        int current = nums[0];
        int N = nums.size();
        for (int idx = 1; idx < N; idx++) {
          if (current == nums[idx]) {
            freq += 1;
          } else {
            freq -= 1;
          }
          
          if (freq < 0) {
            current = nums[idx];
            freq = 1;
          }
        }
        
        return current;
    }
};