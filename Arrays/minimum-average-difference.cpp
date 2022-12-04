// https://leetcode.com/problems/minimum-average-difference/

// This is little memory intensive we can make the space O(1) here

class Solution {
private:
    vector<long long> getPrefixSum(vector<int>& nums, int N) {
      vector<long long> prefixSum(N, 0);
      long long sum = 0;
      for (int idx = 0; idx < N; idx++) {
          int elt = nums[idx];
          sum += elt;
          prefixSum[idx] = sum;
      }
      
      return prefixSum;
    }
public:
    // Time: O(N) | Space: O(N)
    int minimumAverageDifference(vector<int>& nums) {
        int N = nums.size();
        vector<long long> prefixSum = getPrefixSum(nums, N);
        reverse(nums.begin(), nums.end());
        vector<long long> suffixSum = getPrefixSum(nums, N);
        reverse(suffixSum.begin(), suffixSum.end());
        suffixSum.push_back(0);
      
        long long minDifference = INT_MAX;
        int answer = -1;
      
        for (int idx = 0; idx < N; idx++) {
          int numsEnd = N - (idx + 1);
          if (numsEnd == 0) numsEnd = 1;
          long long difference = abs((prefixSum[idx] / (idx + 1)) - (suffixSum[idx + 1] / numsEnd));
          
          if (difference < minDifference) {
            minDifference = difference;
            answer = idx;
          }
        }
        
        return answer;
    }
};