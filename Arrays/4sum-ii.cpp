// https://leetcode.com/problems/4sum-ii/

class Solution {
public:
    // Time: O(N * M) | Space: O(N * M)
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
      unordered_map<int, int> hashMap;
      int answer = 0;
      
      for (int& a: A) {
        for (int& b: B) {
          hashMap[a + b] += 1;
        }
      }
      
      for (int& c: C) {
        for (int& d: D) {
          if (hashMap.count(0 - c - d)) answer += hashMap[0 - c - d];
        }
      }
      return answer;
    }
};