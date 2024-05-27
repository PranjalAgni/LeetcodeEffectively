// https://leetcode.com/problems/word-break-ii/

// Time: O(2^N) | Space: O(N)
class Solution {
private:
    unordered_map<string, bool> getWordsMap(vector<string>& wordDict) {
      unordered_map<string, bool> wordMap;
      for (string& word: wordDict) {
        wordMap[word] = true;
      }
      
      return wordMap;
    }
  
    void helper(string& str, unordered_map<string, bool>& wordMap, int start, int end, string subpart, vector<string>& answer) {
      if (end >= str.length()) {
        if (start == end) {
          answer.push_back(subpart);
        }
        
        return;
      }
      
      helper(str, wordMap, start, end + 1, subpart, answer); 
      string temp = str.substr(start, end - start + 1);
      if (wordMap.find(temp) != wordMap.end()) {
        if (subpart.length() > 0) subpart += " ";
        helper(str, wordMap, end + 1, end + 1, subpart + temp, answer);
      }   
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> answer;
        string current = "";
        unordered_map<string, bool> wordMap = getWordsMap(wordDict);
        helper(s, wordMap, 0, 0, "", answer);
        return answer;
    }
};