// https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/

class Solution {
public:
    // Time: O(N*logN) | Space: O(1)
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int N = nums.size();
        int start = 0;
        int end = N - 1;
      
        int answer = INT_MIN;
        while (start <= end) {
          int current = nums[start] + nums[end];
          answer = max(answer, current);
          start += 1;
          end -= 1;
        }
      
        return answer;
    }
};