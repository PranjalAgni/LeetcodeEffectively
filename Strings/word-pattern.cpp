// https://leetcode.com/problems/word-pattern/
class Solution {
public:
    char SPACE = ' ';
public:
    vector<string> getWords(string s) {
      vector<string> words;
      s.push_back(SPACE);
      string word = "";
      for (char& ch: s) {
        if (ch == SPACE) {
          words.push_back(word);
          word = "";
        } else word += ch;
      }
      
      return words;
    }
    
    // Time: O(N) | Space: O(N)
    bool wordPattern(string pattern, string s) {
      vector<string> words = getWords(s);
      int N = pattern.length();
      if (words.size() != N) return false;
      unordered_map<char, string> patternMap;
      unordered_map<string, char> wordMap;

      for (int idx = 0; idx < N; idx++) {
        string& word = words[idx];
        char& patternChar = pattern[idx];
        string mappedWord = patternMap[patternChar];
        char mappedPattern = wordMap[word];
        if (mappedWord.length() && mappedWord != word) return false;
        if (mappedPattern && mappedPattern != patternChar) return false;
        patternMap[patternChar] = word;
        wordMap[word] = patternChar;
      }
      
      return true;
    }
};