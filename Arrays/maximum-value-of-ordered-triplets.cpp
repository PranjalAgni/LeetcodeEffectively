// https://leetcode.com/contest/weekly-contest-365/problems/maximum-value-of-an-ordered-triplet-ii/

class Solution {
public:
    // Time: O(N) | Space: O(N)
    long long maximumTripletValue(vector<int>& nums) {
        int N = nums.size();
        vector<int> rightMax(N);
        
        rightMax[N - 1] = -1;
        for (int idx = N - 2; idx >= 0; idx--) {
          rightMax[idx] = max(rightMax[idx + 1], nums[idx + 1]);
        }
        
        
        int largestElement = nums[0];
        int minSoFar = INT_MAX;
        long long answer = 0;
      
        for (int idx = 1; idx < N - 1; idx++) {
          minSoFar = min(minSoFar, nums[idx]);
          if (nums[idx] < largestElement) {
            long long a = largestElement - nums[idx];
            long long b = rightMax[idx];
            long long result = a * b;
            answer = max(answer, result);
          }
          largestElement = max(largestElement, nums[idx]);
        }
      
        return answer;
    }
};