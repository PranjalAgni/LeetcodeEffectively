// https://leetcode.com/problems/number-of-matching-subsequences/

class Solution {
private:
    bool isSubsequence(string& str, string& target) {
      int N = str.length();
      int M = target.length();
      if (M > N) return false;
      
      int start = 0;
      int pos = 0;
      while (start < N && pos < M) {
        if (str[start] == target[pos]) {
          pos += 1;
        }
        start += 1;
      }
      
      return pos == M;
    }
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int answer = 0;
        for (string& word: words) {
          if (isSubsequence(s, word)) {
            answer += 1;
          }
        }
      
        return answer;
    }
};