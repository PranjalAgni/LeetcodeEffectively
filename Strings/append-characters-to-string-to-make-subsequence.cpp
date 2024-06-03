// https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/

// Time: O(N) | Space: O(1)
class Solution {
public:
    int appendCharacters(string s, string t) {
        int N = s.length();
        int M = t.length();
          
        int pos = 0;
        for (int idx = 0; idx < N; idx++) {
          if (s[idx] == t[pos]) {
            pos += 1;
          }
          
          if (pos == M) break;
        }
      
        return M - pos;
    }
};