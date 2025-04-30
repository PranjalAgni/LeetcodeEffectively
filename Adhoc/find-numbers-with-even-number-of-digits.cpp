// https://leetcode.com/problems/find-numbers-with-even-number-of-digits/

// Time: O(N) | Space: O(1)
class Solution {
  public:
      int findNumbers(vector<int>& nums) {
          int answer = 0;
          for (int& num: nums) {
              int x = num;
              int count = 0;
              while (num != 0) {
                  num /= 10;
                  count += 1;
              }
  
              if (count % 2 == 0) answer += 1;
          }
  
          return answer;
      }
  };