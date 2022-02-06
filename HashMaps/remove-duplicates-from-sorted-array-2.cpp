// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

class Solution {
public:
    // Time: O(N) | Space: O(1)
    int removeDuplicates(vector<int>& nums) {
        int N = nums.size();
        int pos = 0;
        unordered_map<int, int> freqMap;
      
        for (int idx = 0; idx < N; idx++) {
          freqMap[nums[idx]] += 1;
          if (freqMap[nums[idx]] <= 2) {
            nums[pos] = nums[idx];
            pos += 1;
          }
        }
        
        return pos;
    }
};