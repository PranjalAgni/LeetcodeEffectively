// https://leetcode.com/problems/sum-of-subarray-minimums/
class Solution {
public:
    // Time: O(N) | Space: O(N)
    int sumSubarrayMins(vector<int>& arr) {
        long long MOD = 1e9 + 7;
        int len = arr.size();
        vector<int> nextLeftMin(len, 0);
        vector<int> nextRightMin(len,len + 1);

        stack<int> st;
      
        for (int idx = 0; idx < len; idx++) {
          while(!st.empty() && arr[st.top() - 1] > arr[idx]) {
            st.pop();
          }
          
          if(!st.empty()) nextLeftMin[idx] = st.top();
          st.push(idx + 1);
        }
      
        st = stack<int>();
      
        for (int idx = 0; idx < len; idx++) {
          while(!st.empty() && arr[idx] < arr[st.top() - 1]) {
            nextRightMin[st.top() - 1] = idx + 1;
            st.pop();
          }
          
          st.push(idx + 1);
        }
      
        int ans = 0;
        for (int idx = 0; idx < len; idx++) {
          int leftNums = idx + 1 - nextLeftMin[idx];
          int rightNums = nextRightMin[idx] - (idx + 1);
          ans = (ans + (long)leftNums * rightNums * arr[idx]) % MOD;
        }
      
        return ans;
    }
};

