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
public:
    // Time: O(M*log(N)) | Space: O(N)
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int N = nums.size();
        int M = queries.size();
        vector<int> answer(M);
        sort(nums.begin(), nums.end());
        vector<int> prefixSum = getPrefixSum(nums);
      
        for (int idx = 0; idx < M; idx++) {
          int ans = 0;
          int elt = queries[idx];
          // find longest subsequence in prefixSum
          for (int pos = 0; pos < N; pos++) {
            if (prefixSum[pos] <= elt) {
              ans = max(ans, pos + 1);
            }
          }
          
          answer[idx] = ans;
        }

        for (int idx = 0; idx < M; idx++) {
          int elt = queries[idx];
          
          // binary search to find the answer
          int ans = upper_bound(prefixSum.begin(), prefixSum.end(), elt) - prefixSum.begin();

          // searching linearly
          // for (int pos = 0; pos < N; pos++) {
          //   if (prefixSum[pos] <= elt) {
          //     ans = max(ans, pos + 1);
          //   }
          // }
          
          answer[idx] = ans;
        }
      
        return answer;
    }
};