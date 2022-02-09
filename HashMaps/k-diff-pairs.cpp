// https://leetcode.com/problems/k-diff-pairs-in-an-array/

class Solution {
public:
    // Time: O(N) | Space: O(N)
    int findPairs(vector<int>& nums, int k) {
        int N = nums.size();
        unordered_map<int, int> freqMap;
        for (int& num: nums) {
          freqMap[num] += 1;
        }
        unordered_set<int> hashSet;  
        int answer = 0;
        for (int& num: nums) {
          int target = num + k;
          freqMap[num] -= 1;
          
          if (freqMap[target]) {
            hashSet.insert(num);
          }
          
          freqMap[num] += 1;
        }
      
        return hashSet.size();
    }
};