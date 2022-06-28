// https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/

// Nice string based problem
// Time: O(N) | Space: O(N)
class Solution {
private:
    vector<int> getFrequencyList(string& str) {
      unordered_map<char, int> freqMap;
      for (char ch: str) {
        freqMap[ch] += 1;
      }
      
      vector<int> freqList;
      for (const auto [key, value]: freqMap) {
        freqList.push_back(value);
      }
      
      return freqList;
    }
public:
    int minDeletions(string s) {
      vector<int> freqList = getFrequencyList(s);
      sort(freqList.begin(), freqList.end(), greater<int>());
      
      int keep = 0;
      int prev = INT_MAX;
      
      for (int freq: freqList) {
        if (!prev) break;
        prev = min(freq, prev - 1);
        keep += prev;
      }
      
      return s.length() - keep;
    }
};