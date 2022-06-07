// https://leetcode.com/problems/running-sum-of-1d-array/

class Solution {
public:
    // Time: O(N) | Space: O(N)
    vector<int> runningSum(vector<int>& nums) {
        int N = nums.size();
        int sum = 0;
        vector<int> answer(N);
        for (int idx = 0; idx < N; idx++) {
          sum += nums[idx];
          answer[idx] = sum;
        }
      
        return answer;
    }
};