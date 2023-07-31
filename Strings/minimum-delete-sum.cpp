// https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/

// Currently solution in WIP
// all this time I was building the wrong solution

// We need to maintain the order of character and then delete this means
// to solve this we need to just keep the longest common subsequence and delete everything else

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int N = s1.length();
        int M = s2.length();
        vector<int> freqMap1(26, 0);
        vector<int> freqMap2(26, 0);
      
      // delete // deeelt // eelt
      // leet // eelt // eelt
        for (int idx = 0; idx < N; idx++) {
          freqMap1[s1[idx] - 'a'] += 1;
        }
      
        for (int idx = 0; idx < M; idx++) {
          freqMap2[s2[idx] - 'a'] += 1;
        }
        
        int answer = 0;
        bool isDeletedFromString1 = false;
        bool isDeletedFromString2 = false;
        for (int idx = 0; idx < 26; idx++) {
          if (freqMap1[idx] != freqMap2[idx]) {
            if (freqMap1[idx] > freqMap2[idx]) isDeletedFromString1 = true;
            else isDeletedFromString2 = true;
            int difference = abs(freqMap1[idx] - freqMap2[idx]);
            freqMap1[idx] = min(freqMap1[idx], freqMap2[idx]);
            freqMap2[idx] = min(freqMap1[idx], freqMap2[idx]);
            int ascii = 97 + idx;
            answer += (ascii * difference);
          }
        }
      
        cout << "Current answer " << answer << endl;
        if (!isDeletedFromString1 || !isDeletedFromString2) {
          for (int idx = 0; idx < 26; idx++) {
            int count1 = freqMap1[idx];
            int count2 = freqMap2[idx];
            
            if (count1 > 0 && count1 == count2) {
              int ascii = 97 + idx;
              cout << "ascii value of char is " << ascii << endl;
              cout << answer << " + " << (ascii * 2) << endl;
              answer += (ascii * 2);
              break;
            } 
          }
        }
        
        return answer;
    }
};