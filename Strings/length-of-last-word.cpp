// https://leetcode.com/problems/length-of-last-word/

class Solution {
public:
    // Time: O(N) | Space: O(1)
    int lengthOfLastWord(string s) {
      int N = s.length();
      int end = N - 1;
      
      while (end >= 0 && s[end] == ' ') {
        end -= 1;
      }
      
      int right = end;
      
      while (end >= 0 && s[end] != ' ') {
        end -= 1;
      }
      
      int left = end + 1;
      return right - left + 1;
    }
};