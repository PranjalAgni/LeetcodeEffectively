// https://leetcode.com/problems/get-equal-substrings-within-budget/

// Nice sliding window based problem
class Solution {
public:
    // Time: O(N) | Space: O(1)
    int equalSubstring(string s, string t, int maxCost) {
        int N = s.length();
        int left = 0;
        int right = 0;
        int currentCost = 0;
        int answer = 0;
      
        while (right < N) {
          currentCost += abs(s[right] - t[right]);
          while (currentCost > maxCost) {
            currentCost -= abs(s[left] - t[left]);
            left += 1;
          }
          
          answer = max(answer, right - left + 1);
          right += 1;
        }
      
        return answer;
    }
};