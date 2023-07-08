// https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/

class Solution {
public:
    // Time: O(N) | Space: O(N)
    int longestSubarray(vector<int>& nums) {
      int N = nums.size();
      int count = 0;
      vector<int> countList;
      for (int idx = 0; idx < N; idx++) {
        if (nums[idx] == 0) {
          countList.push_back(count);
          count = 0;
        } else {
          count += 1;  
        }
      }
      
      if (count) countList.push_back(count);
      
      int countSize = countList.size();
      if (countSize == 1) return max(countList[0] - 1, 0);
      int answer = 0;
      for (int idx = 1; idx < countSize; idx++) {
        answer = max(answer, countList[idx] + countList[idx - 1]);
      }
      
      return answer;
    }

    // Time: O(N) | Space: O(1)
    int longestSubarray(vector<int>& nums) {
      int N = nums.size();
      int count = 0;
      int answer = 0;
      int prevCount = -1;
      for (int idx = 0; idx < N; idx++) {
        if (nums[idx] == 0) {
          answer = max(answer, count + prevCount);
          prevCount = count;
          count = 0;
        } else {
          count += 1;  
        }
      }
      
      answer = max(answer, prevCount + count);
      return answer;
    }
};