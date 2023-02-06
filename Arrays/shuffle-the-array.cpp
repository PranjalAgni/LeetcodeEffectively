// https://leetcode.com/problems/shuffle-the-array/

class Solution {
public:
    // Time: O(N/n) | Space: O(N)
    // N = number of elements in nums
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> answer;
        int start1 = 0;
        int start2 = n;
        int N = nums.size();
      
        while (start1 < n && start2 < N) {
          answer.push_back(nums[start1]);
          answer.push_back(nums[start2]);
          start1 += 1;
          start2 += 1;
        }
      
        return answer;
    }
};