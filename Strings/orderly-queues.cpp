// https://leetcode.com/problems/orderly-queue/

class Solution {
public:
    // Time: O(N) | Space: O(1)
    string orderlyQueue(string s, int k) {
        if (k > 1) {
          sort(s.begin(), s.end());
          return s;
        }
        
        int N = s.length();
        string res = s;
        for (int idx = 1; idx < N; idx++) {
          res = min(res, s.substr(idx) + s.substr(0, idx));
        }
      
        return res;
    }
};