// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/
// Time: O(N) | Space: O(1)
class Solution {
  private:
      bool isValid(vector<int>& letters) {
          for (int idx = 0; idx < 3; idx++) {
              if (letters[idx] == 0) return false;
          }
  
          return true;
      }
  
      int computeTotalSubstrings(string& str) {
          int N = str.length();
          int left = 0;
          int right = 0;
          vector<int> letters(3, 0);
  
          int answer = 0;
  
          while (right < N) {
              letters[str[right] - 'a'] += 1;
              while (isValid(letters) && left <= right) {                
                  answer += N - right;
                  letters[str[left] - 'a'] -= 1;
                  left += 1;
              }
              right += 1;
          }
  
          return answer;
      }
  public:
      int numberOfSubstrings(string s) {
          return computeTotalSubstrings(s);
      }
  };