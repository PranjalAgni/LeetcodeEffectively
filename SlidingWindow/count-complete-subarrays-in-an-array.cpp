// https://leetcode.com/problems/count-complete-subarrays-in-an-array/

// Time: O(N) | Space: O(N)
// This is a standard sliding window problem
// We will pass through a element atmost twice 
class Solution {
  public:
      int countCompleteSubarrays(vector<int>& nums) {
          int N = nums.size();
          unordered_map<int, int> freqMap;
          int count = 0;
          for (int& elt: nums) {
              freqMap[elt] += 1;
              if (freqMap[elt] == 1) count += 1;
          }
  
          int left = 0;
          int right = 0;
          unordered_map<int, int> currentFreqMap;
          int currentCount = 0;
          int answer = 0;
          while (right < N) {
              currentFreqMap[nums[right]] += 1;
              if (currentFreqMap[nums[right]] == 1) {
                  currentCount += 1;
              }
  
              // this window has all the distinct elements now
              while (currentCount == count) {
                  answer += N - right;
  
                  // we can move left now
                  currentFreqMap[nums[left]] -= 1;
                  if (currentFreqMap[nums[left]] == 0) {
                      currentCount -= 1;
                  }
                  left += 1;
              }
  
              right += 1;
  
          }
  
          return answer;
      }
  };
  