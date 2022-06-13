// https://leetcode.com/problems/maximum-erasure-value/

// Sliding window approach
class Solution {
private:
    vector<int> getPrefixSum(vector<int>& nums) {
      int N = nums.size();
      int sum = 0;
      vector<int> prefixSum(N);
      for (int idx = 0; idx < N; idx++) {
        sum += nums[idx];
        prefixSum[idx] = sum;
      }
      
      return prefixSum;
    }
public:
    // Time: O(N) | Space: O(N)
    int maximumUniqueSubarray(vector<int>& nums) {
        int N = nums.size();
        vector<int> prefixSum = getPrefixSum(nums);
        unordered_map<int, int> hashMap;
        int left = 0;
        int right = 0;
        int answer = 0;
        int currentAnswer = 0;
        while (right < N) {
          
          int curr = nums[right];
          if (hashMap.find(curr) != hashMap.end()) {
            int duplicateIndex = hashMap[curr];
            while (left <= duplicateIndex) {
              currentAnswer -= nums[left];
              left += 1;
            }
          }
          
          hashMap[curr] = right;
          currentAnswer += curr;
          right += 1;
          answer = max(answer, currentAnswer);
        }
      
        return answer;
    }
};