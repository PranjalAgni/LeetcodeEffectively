// https://leetcode.com/problems/ransom-note/

class Solution {
public:
    // Time: O(N) | Space: O(1)
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> freqMap(26, 0);
        for (char& ch: magazine) {
          freqMap[ch - 'a'] += 1;
        }
      
        for (char& ch: ransomNote) {
          if (freqMap[ch - 'a'] <= 0) return false;
          freqMap[ch - 'a'] -= 1;
        }
      
        return true;
    }
};