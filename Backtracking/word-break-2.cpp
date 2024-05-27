class Solution {
private:
    unordered_map<string, bool> getWordsMap(vector<string>& wordDict) {
      unordered_map<string, bool> wordMap;
      for (string& word: wordDict) {
        wordMap[word] = true;
      }
      
      return wordMap;
    }
  
    void helper(string& str, unordered_map<string, bool>& wordMap, int start, int end, string subpart) {
      if (end >= str.length()) {
        return;
      }
      
      string temp = str.substr(start, end - start + 1);
      if (wordMap.find(temp) != wordMap.end()) {
        helper(str, wordMap, start, end + 1, subpart + " " + temp);
      }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> answer;
        string current = "";
        unordered_map<string, bool> wordMap = getWordsMap(wordDict);
        helper(s, wordMap, 0, 0, "");
    }
};