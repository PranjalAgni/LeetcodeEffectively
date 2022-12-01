// https://leetcode.com/problems/determine-if-string-halves-are-alike/

class Solution {
private:
    bool isVowel(char ch) {
      return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    } 
public:
    // Time: O(N) | Space: O(1)
    bool halvesAreAlike(string s) {
        int N = s.length();
        int count1 = 0;
        int count2 = 0;
        for (int idx = 0; idx < N / 2; idx++) {
          if (isVowel(tolower(s[idx]))) count1 += 1;
        }
      
        for (int idx = N / 2; idx < N; idx++) {
          if (isVowel(tolower(s[idx]))) count2 += 1;
        }
      
        return count1 == count2;
    }
};