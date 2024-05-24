// https://leetcode.com/problems/maximum-score-words-formed-by-letters/

// Time: O(2^N) | Space: O(N)
class Solution {
private:
  vector<int> constructCount(vector<char>& letters) {
    vector<int> count(26, 0);
    for (char& letter: letters) {
      count[letter - 'a'] += 1;
    }
    
    return count;
  }
  
  void backtracking(vector<string>& words, vector<int>& score, vector<int>& count, vector<int>& letterCount, int pos, int temp, int& answer) {
    for (int idx = 0; idx < 26; idx++) {
      if (letterCount[idx] > count[idx]) return;
    }
    
    answer = max(answer, temp);
    for (int idx = pos; idx < words.size(); idx++) {
      for (char& ch: words[idx]) {
        letterCount[ch - 'a'] += 1;
        temp += score[ch - 'a'];
      }
      
      backtracking(words, score, count, letterCount, idx + 1, temp, answer);
      
      for (char& ch: words[idx]) {
        letterCount[ch - 'a'] -= 1;
        temp -= score[ch - 'a'];
      }
    }
  }
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> count = constructCount(letters);
        vector<int> letterCount(26, 0);
        int answer = 0;
        backtracking(words, score, count, letterCount, 0, 0, answer);
        return answer;
        
    }
};