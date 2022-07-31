// https://leetcode.com/problems/word-subsets/

class Solution {
private:
    unordered_map<char, int> count(string& word) {
      unordered_map<char, int> hashMap;
      for (char& ch: word) {
        hashMap[ch] += 1;
      }
      
      return hashMap;
    }
public:
    // Time: O(N) | Space: O(26)
    // N = max(len(words1), len(words2))
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char, int> freqMap;
        for (string& word: words2) {
          unordered_map<char, int> currentMap = count(word);
          for (char ch = 'a'; ch <= 'z'; ch++) {
            freqMap[ch] = max(freqMap[ch], currentMap[ch]);
          }
        }
        
        vector<string> answer;
        for (string& word: words1) {
          unordered_map<char, int> currentMap = count(word);
          bool isUniversal = true;
          for (char ch = 'a'; ch <= 'z'; ch++) {
            if (currentMap[ch] < freqMap[ch]) {
              isUniversal = false;
              break; 
            }
          }
          if (isUniversal) answer.push_back(word);
        }
      
        return answer;
    }
};