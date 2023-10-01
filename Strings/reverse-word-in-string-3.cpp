// https://leetcode.com/problems/reverse-words-in-a-string-iii/\

class Solution {
public:
    // Time: O(N) | Space: O(1)
    string reverseWords(string s) {
      int N = s.length();
      int start = 0;
      int end = 0;
      string answer = "";
      while (end < N) {
       if (s[end] == ' ' || end == N - 1) {
         int newEnd = (end == N - 1) ? end : end - 1;
         string word = "";
         for (int idx = newEnd; idx >= start; idx--) {
           word += s[idx];
         }
         
         answer += word;
         if (s[end] == ' ') answer += " ";
         start = end + 1;
       }
       
       end += 1; 
      }
      
      return answer;
    }
};