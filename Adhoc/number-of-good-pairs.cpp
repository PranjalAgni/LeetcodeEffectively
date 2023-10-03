// https://leetcode.com/problems/number-of-good-pairs/

class Solution {
public:
    // Time: O(N) | Space: O(N)
    int numIdenticalPairs(vector<int>& nums) {
        int N = nums.size();
        int answer = 0;
        unordered_map<int, int> freqMap;
        for (int idx = 0; idx < N; idx++) {
          freqMap[nums[idx]] += 1;
        }
      
        for (const auto& elt: freqMap) {
          int val = elt.second;
          int goodPairs = (val * (val - 1)) / 2;
          answer += goodPairs;
        }
      
        return answer;
    }
};