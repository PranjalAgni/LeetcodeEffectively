// https://leetcode.com/problems/summary-ranges/

class Solution {
public:
    // Time: O(N) | Space: O(N)
    // N = length of list
    vector<string> summaryRanges(vector<int>& nums) {
      int N = nums.size();
      if (N == 0) return {};
      int start = 1;
      int end = N;
      int left = 0;
      vector<string> answer;
      string current = to_string(nums[left]);
      int incrementBy = 1;
      
      while (start < end) {
        if (nums[left] + incrementBy != nums[start]) {
          if (nums[left] != nums[start - 1]) current += "->" + to_string(nums[start - 1]);
          answer.push_back(current);
          left = start;
          current = to_string(nums[left]);
          incrementBy = 0;
        }
        
        start += 1;
        incrementBy += 1;
      }
      
      
      if (nums[left] != nums[start - 1]) current += "->" + to_string(nums[start - 1]);
     
      answer.push_back(current);
      return answer;
      
    }
};