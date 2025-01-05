// https://leetcode.com/problems/shifting-letters-ii/

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int N = s.length();
        vector<char> letters;
        for (char& ch: s) {
            letters.push_back(ch);
        }

        for (vector<int>& shift: shifts) {
            int start = shift[0];
            int end = shift[1];
            int direction = shift[2];

            for (int pos = start; pos <= end; pos++) {
                char ch = letters[pos];
                if (direction == 0) {
                    if (ch == 'a') ch = 'z';
                    else ch -= 1;
                }
                else {
                    if (ch == 'z') ch = 'a';
                    else ch += 1;
                }
                
                letters[pos] = ch;
            }
        }

        string answer(letters.begin(), letters.end());
        return answer;
    }
};