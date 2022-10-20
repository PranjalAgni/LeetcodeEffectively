// https://leetcode.com/problems/integer-to-roman/
class Solution {
public:
    // Time: O(N) | Space: O(1)
    string intToRoman(int num) {
      vector<string> romanSymbol = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
      vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
      int N = romanSymbol.size();
      string  romanAnswer = "";
      while (num > 0) {
        int idx = 0;
        while (idx < N) {
          if (num >= values[idx]) break;
          idx += 1;
        }
        
        romanAnswer += romanSymbol[idx];
        num -= values[idx];
      }
      return romanAnswer;
    }
};