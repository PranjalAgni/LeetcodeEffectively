// https://leetcode.com/problems/minimum-absolute-difference/


class Solution {
public:
    // Time: O(N * logN) | Space: O(N)
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int N = arr.size();
        vector<vector<int>> answer;
        int minDiff = INT_MAX;
        for (int idx = 1; idx < N; idx++) {
          minDiff = min(minDiff, abs(arr[idx] - arr[idx - 1]));
        }
      
        for (int idx = 1; idx < N; idx++) {
          int currDiff = abs(arr[idx] - arr[idx - 1]);
          if (currDiff == minDiff) answer.push_back({arr[idx - 1], arr[idx]});
        }
      
        return answer;
    }
};