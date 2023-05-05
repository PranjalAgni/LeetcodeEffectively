// https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/

class Solution {
private:
    bool isVowel(char& ch) {
      if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
      return false;
    }
  
public:
    // Time: O(N) | Space: O(1)
    int maxVowels(string s, int k) {
       int N = s.length();
       if (k > N) return 0; 
       int left = 0;
       int right = 0;
       int maxVowels = 0; 
       int currentVowels = 0; 
       while (right < N) {
         char ch = s[right];
         if (isVowel(ch)) currentVowels += 1;
         if (right - left + 1 == k) {
           maxVowels = max(maxVowels, currentVowels);
           if (isVowel(s[left])) currentVowels -= 1; 
           left += 1;
         }
         right += 1;
       }
      
       return max(maxVowels, currentVowels);
    }
};