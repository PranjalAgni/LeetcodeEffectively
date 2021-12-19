// https://leetcode.com/contest/weekly-contest-272/problems/find-first-palindromic-string-in-the-array/

class Solution {
private:
    bool isPalindrome(string& word) {
      int N = word.length();
      int left = 0;
      int right = N - 1;
      
      while (left < right) {
        if (word[left] != word[right]) return false;
        left += 1;
        right -= 1;
      }
      
      return true;
    }
public:
    // Time: O(N) | Space: O(1)
    string firstPalindrome(vector<string>& words) {
        for (string& word: words) {
          if (isPalindrome(word)) return word;
        }
        
        return "";
    }
};