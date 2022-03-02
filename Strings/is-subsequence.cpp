class Solution {
public:
    // Time: O(N) | Space: O(1)
    // N = length of t
    bool isSubsequence(string s, string t) {
        if (s == t) return true;
        int pos = 0;
        int N = s.length();
        for (char& ch: t) {
          if (s[pos] == ch) {
            pos += 1;
          }
          
          if (pos == N) return true;
        }
      
        return false;
    }
};