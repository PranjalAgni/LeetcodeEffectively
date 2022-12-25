// https://leetcode.com/problems/longest-subsequence-with-limited-sum/

// Not so optimized solution, need to fix this as it is working on subarrays not subsequences

// This uses prefix and suffix sum to compute result

class Solution {
private:
    vector<int> getPrefixSum(vector<int>& nums) {
      int N = nums.size();
      vector<int> prefixSum(N, 0);
      prefixSum[0] = nums[0];
      for (int idx = 1; idx < N; idx++) {
        prefixSum[idx] += nums[idx] + prefixSum[idx - 1];
      }
      
      return prefixSum;
    }
  
    vector<int> getSuffixSum(vector<int>& nums) {
      int N = nums.size();
      vector<int> suffixSum(N, 0);
      suffixSum[N - 1] = nums[N - 1];
      for (int idx = N - 2; idx >= 0; idx--) {
        suffixSum[idx] += nums[idx] + suffixSum[idx + 1];
      }
      
      return suffixSum;
    }
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int N = nums.size();
        int M = queries.size();
        vector<int> answer(M);
      
        vector<int> prefixSum = getPrefixSum(nums);
        vector<int> suffixSum = getSuffixSum(nums);
        
        int ans = 0;
        for (int idx = 0; idx < M; idx++) {
          int elt = queries[idx];
          // find longest subsequence in prefixSum
          for (int pos = 0; pos < N; pos++) {
            if (prefixSum[pos] <= elt) {
              ans = max(ans, pos + 1);
            }
          }
          
          // find longest subsequence in suffixSum
          for (int pos = N - 1; pos >= 0; pos--) {
            if (suffixSum[pos] <= elt) {
              ans = max(ans, N - pos);
            }
          }
          
          answer[idx] = ans;
        }
      
        return answer;
    }
};

// 4 9 11 12
// 12 8 3  1

// 4 5 2 1
// sum = 0
// 