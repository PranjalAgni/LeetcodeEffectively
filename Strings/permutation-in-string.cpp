// https://leetcode.com/problems/permutation-in-string/

class Solution {
public:
    // Time: O(N) | Space: O(1)
    bool checkInclusion(string s1, string s2) {
      int N = s1.length();
      int M = s2.length();
      if (N > M) return false;
      vector<int> freqMap(26, 0);
      
      // fill the freqMap with the characters in string s1
      for (char& ch: s1) freqMap[ch - 'a'] += 1;
      
      // apply the sliding window technique
      int left = 0;
      int right = 0;
      int count = N;
      
      while (right < M) {
        if (freqMap[s2[right] - 'a'] > 0) {
          freqMap[s2[right] - 'a'] -= 1;
          count -= 1;
          right += 1;
          if (count == 0) return true;
        } else if (left == right) {
          left += 1;
          right += 1;
        } else {
          freqMap[s2[left] - 'a'] += 1;
          left += 1;
          count += 1;
        }
      }
      
      return false;
    }
};