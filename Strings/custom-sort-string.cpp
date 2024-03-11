// https://leetcode.com/problems/custom-sort-string/

// Nice string and hashmap based problem
class Solution {
public:
    // Time: O(N) | Space: O(26)
    string customSortString(string order, string s) {
        int N = order.length();
        vector<int> freqMap(26, 0);
      
        for (char& ch: s) {
          freqMap[ch - 'a'] += 1;
        }
      
        string answer = "";
      
        // now we can check something in freq map
        // iterate in order first and map characters
        for (int idx = 0; idx < N; idx++) {
          char ch = order[idx];
          int freq = freqMap[ch - 'a'];
          while (freq-- > 0) {
            answer += ch;
          }
          freqMap[ch - 'a'] = 0;
        }
      
        // map remaining characters
        for (int idx = 0; idx < 26; idx++) {
          int freq = freqMap[idx];
          if (freq > 0) {
            char ch = 'a' + idx;
            while (freq-- > 0) {
              answer += ch;
            }
          }
        }
      
        return answer;
    }
};