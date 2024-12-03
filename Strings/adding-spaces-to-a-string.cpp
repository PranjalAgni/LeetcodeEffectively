// https://leetcode.com/problems/adding-spaces-to-a-string/

// Time: O(N) | Space: O(N)
class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string answer;
        int pos = 0;
        int N = s.length();
        int totalSpaces = spaces.size();
        for (int idx = 0; idx < N; idx++) {
            char ch = s[idx];
            if (pos < totalSpaces && idx == spaces[pos]) {
                answer += " ";
                pos += 1;
            }
            
            answer += ch;
        }
        return answer;
    }
};