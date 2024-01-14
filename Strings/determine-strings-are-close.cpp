// https://leetcode.com/problems/determine-if-two-strings-are-close/


class Solution {
public:
    // Time: O(N) | Space: O(N)
    bool closeStrings(string word1, string word2) {
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);
      
        set<char> sword1;
        set<char> sword2;
      
        for (char& ch: word1) {
          freq1[ch - 'a'] += 1;
          sword1.insert(ch);
        }
      
        for (char& ch: word2) {
          freq2[ch - 'a'] += 1;
          sword2.insert(ch);
        }
      
        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());
      
        return freq1 == freq2 && sword1 == sword2;
    }
};