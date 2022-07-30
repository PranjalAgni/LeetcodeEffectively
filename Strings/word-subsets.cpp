// https://leetcode.com/problems/word-subsets/

class Solution {
private:
    bool isSubstring(string& a, string& b, unordered_map<char, int> hashMap) {
      int N = a.length();
      int M = b.length();
      if (M > N) return false;
      
      for (char ch: b) {
        hashMap[ch] -= 1;
        if (hashMap[ch] < 0) return false;
      }
      
      return true;
      
    }
  
    bool isUniversalString(string& word, vector<string>& words, unordered_map<char, int> hashMap) {
      for (string& subword: words) {
        if (!isSubstring(word, subword, hashMap)) return false;
      }
      
      return true;
    }
  
    vector<unordered_map<char, int>> preprocess(vector<string>& words) {
      vector<unordered_map<char, int>> hashMapList;
      for (string& word: words) {
        unordered_map<char, int> hashMap;
        for (char& ch: word) {
          hashMap[ch] += 1;
        }
        hashMapList.push_back(hashMap);
      }
      
      return hashMapList;
    }
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> answer;
        vector<unordered_map<char, int>> hashMapList = preprocess(words1);
        int idx = 0;
        for (string& word: words1) {
          if (isUniversalString(word, words2, hashMapList[idx])) {
            answer.push_back(word);
          }
          
          idx += 1;
        }
        return answer;
    }
};