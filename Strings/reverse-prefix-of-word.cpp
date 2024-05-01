// https://leetcode.com/problems/reverse-prefix-of-word/
class Solution {
public:
    // Time: O(N) | Space: O(N)
    string reversePrefix(string word, char ch) {
        int N = word.length();
        int idx = 0;
        for (idx = 0; idx < N; idx++) {
          if (word[idx] == ch) {
            break;
          }
        }
      
        if (idx == N) return word;
        string prefix = word.substr(0, idx + 1);
        string suffix = word.substr(idx + 1);
      
        reverse(prefix.begin(), prefix.end());
      
        return prefix + suffix;
    }
};