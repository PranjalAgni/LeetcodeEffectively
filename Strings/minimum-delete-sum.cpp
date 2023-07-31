// https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/

// Currently solution in WIP
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int N = s1.length();
        int M = s2.length();
        vector<int> freqMap1(26, 0);
        vector<int> freqMap2(26, 0);
      
        for (int idx = 0; idx < N; idx++) {
          freqMap1[s1[idx] - 'a'] += 1;
        }
      
        for (int idx = 0; idx < M; idx++) {
          freqMap2[s2[idx] - 'a'] += 1;
        }
        
        int answer = 0;
        for (int idx = 0; idx < 26; idx++) {
          if (freqMap1[idx] != freqMap2[idx]) {
            int difference = abs(freqMap1[idx] - freqMap2[idx]);
            int ascii = 97 + idx;
            answer += (ascii * difference);
          }
        }
        
        return answer;
    }
};