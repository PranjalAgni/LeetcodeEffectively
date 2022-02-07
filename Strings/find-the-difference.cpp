// https://leetcode.com/problems/find-the-difference/

class Solution {
public:
    // Time: O(N) | Space: O(N)
    char findTheDifference(string s, string t) {
        unordered_map<char, int> freqMap;
        for (char& ch: s) {
          freqMap[ch] += 1;
        }
      
        for (char& ch: t) {
          freqMap[ch] -= 1;
          if (freqMap[ch] < 0) {
            return ch;
          }
        }
      
        return '$';
    }
};