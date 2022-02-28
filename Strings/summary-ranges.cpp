class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
      int N = nums.size();
      int start = 1;
      int end = N;
      int left = 0;
      int orignalLeft = left; 
      vector<string> answer;
      while (start < end) {
        if (nums[left] + 1 == nums[start]) {
          left += 1;
        } else {
          string current = to_string(nums[orignalLeft]) + "->" + to_string(nums[start - 1]);
          answer.push_back(current);
          left = start;
          orignalLeft = left;
        }
        start += 1;
      }
      
      
      string current = to_string(nums[orignalLeft]) + "->" + to_string(nums[start - 1]);
     
      answer.push_back(current);
      return answer;
      
    }
};