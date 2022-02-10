// https://leetcode.com/problems/subarray-sum-equals-k/

class Solution {
public:
    // Time: O(N) | Space: O(1)
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        freqMap[0] = 1;
        int sum = 0;
        int answer = 0;
      
        for(int& num: nums) {
          sum += num;
          answer += freqMap[sum - k];
          freqMap[sum] += 1;
        }
      
        return answer;
    }
};