// https://leetcode.com/problems/longest-palindrome
// Time: O(N) | Space: O(N)
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> freqMap;
        for (char& ch: s) {
          freqMap[ch] += 1;
        }
      
        bool takeOddOnce = true;
        int answer = 0;
        for (auto& it: freqMap) {
          int val = it.second;
          if (val % 2 == 0) answer += val;
          else if (takeOddOnce) {
            answer += val;
            takeOddOnce = false;
          } else {
            answer += (val - 1);
          }
        }
      
        return answer;
    }
};
