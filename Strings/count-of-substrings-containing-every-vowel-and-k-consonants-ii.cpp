// https://leetcode.com/problems/count-of-substrings-containing-every-vowel-and-k-consonants-ii
class Solution {
  private:
      bool isVowel(char& ch) {
          return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
      }
  
      bool isValid(vector<int>& letters, int& k) {
          int totalVowels = 0;
          int consonants = 0;
          for (char ch = 'a'; ch <= 'z'; ch++) {
              int idx = ch - 'a';
              if (isVowel(ch)) {
                  if (letters[idx] > 0) totalVowels += 1;
              } else {
                  if (letters[idx] > 0) consonants += 1;
              }
          }
  
          return totalVowels == 5 && consonants == k;
          
      }
  public:
      long long countOfSubstrings(string word, int k) {
          int N = word.length();
          int left = 0;
          int right = 0;
          int consonants = 0;
          vector<int> letters(26, 0);
          long long answer = 0;
  
          // sliding window approach
          while (right < N) {
              char ch = word[right];
              int pos = ch - 'a';
              letters[pos] += 1;
              if (!isVowel(ch)) {
                  consonants += 1;
              }
  
              // updating letters so we can remove extra consonants
              while (consonants > k && left < right) {
                  char currChar = word[left];
                  int letterPos = currChar - 'a';
                  letters[letterPos] -= 1;
  
                  if (!isVowel(currChar)) {
                      consonants -= 1;               
                  }
  
                  left += 1;
              }
  
              if (isValid(letters, k)) {
                  string correct = word.substr(left, right - left + 1);
                  // cout << "consonants = " << consonants << "left = " << left << "right = " << right << endl;
                  // cout << "this ans = " << correct << endl;
                  answer += 1;
              }
              right += 1;
          }
  
          return answer;
      }
  };