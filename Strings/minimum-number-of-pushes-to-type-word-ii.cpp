// https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/submissions/

// TC: O(N) | Space: O(1)
/** 
The time complexity of this solution can be broken down as follows:

Counting letter frequencies: O(n), where n is the length of the input word.
Creating and sorting the frequency array: O(1), as it always deals with 26 elements.
Calculating answer: O(1), as it iterates over at most 26 elements.
*/

class Solution {
private:  
    vector<int> getFreqSortedCharList(string& word) {
      vector<int> freqList(26, 0);
      for (char& ch: word) {
        freqList[ch - 'a'] += 1;
      }
      
      sort(freqList.rbegin(), freqList.rend());
      return freqList;
    }
public:
    int minimumPushes(string word) {
        vector<int> freqSorted = getFreqSortedCharList(word);
        int currentCharCount = 0;
        int answer = 0;
        for (int& times: freqSorted) {
          if (times == 0) break;
          answer += (currentCharCount / 8 + 1) * times;
          currentCharCount += 1;
        }
      
        return answer;
    }
};
