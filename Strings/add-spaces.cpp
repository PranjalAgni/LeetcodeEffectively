// https://leetcode.com/contest/weekly-contest-272/problems/adding-spaces-to-a-string/

class Solution {
public:
    // Time: O(N) | Space: O(N)
    string addSpaces(string s, vector<int>& spaces) {
        int N = s.length();
        string answer = "";
        int pos = 0;
        int M = spaces.size();
        for (int idx = 0; idx < N; idx++) {
          if (pos < M && spaces[pos] == idx) {
            answer.push_back(' ');
            pos += 1;
          }
          answer.push_back(s[idx]);
        }
      
        return answer;
    }
};