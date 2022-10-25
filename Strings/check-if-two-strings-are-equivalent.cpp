// https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/

class Solution {
public:
    // Time: O(N) | Space: O(1)
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
      int word1Idx = 0;
      int word2Idx = 0;
      int start1 = 0;
      int start2 = 0;
      int N = word1.size();
      int M = word2.size();

      while (word1Idx < N || word2Idx < M) {
        // if any word list is exhausted then return false
        if (word1Idx >= N || word2Idx >= M) return false;
        int word1Len = word1[word1Idx].length();
        int word2Len = word2[word2Idx].length();
        
        // main check to see if characters are equal
        if (word1[word1Idx][start1] != word2[word2Idx][start2]) return false;
        start1 += 1;
        start2 += 1;
        
        // update the index of character and in word list if current word is over
        if (start1 >= word1Len) {
          start1 = 0;
          word1Idx += 1;
        }
        
        // update the index of character and in word list if current word is over
        if (start2 >= word2Len) {
          start2 = 0;
          word2Idx += 1;
        }
      }
      return true;
    }
};