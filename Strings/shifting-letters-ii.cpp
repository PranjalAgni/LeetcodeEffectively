// https://leetcode.com/problems/shifting-letters-ii/

// Got introduced to scanline algorithm 
/**
* MORE-INFO 

This is a way/trick to achieve adding k to the range [l, r). This works well for questions where we don't need to give the answer immediately, but can perform all the queries, and give the combined answer after performing all the queries. In the other case, we might need to use range data-structures that can perform the updates immediately, like segment tree or fenwick tree.
*/
// Time: O(N) | Space: O(N)
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int N = s.length();
        vector<int> scanline(N + 1, 0);
        for (vector<int>& shift: shifts) {
            int start = shift[0];
            int end = shift[1];
            int direction = shift[2];
            if (direction == 1) {
                // forward
                scanline[start] += 1;
                scanline[end + 1] -= 1;
            } else {
                // backward
                scanline[start] -= 1;
                scanline[end + 1] += 1;
            }
        }

        for (int idx = 1; idx <= N; idx++) {
            scanline[idx] += scanline[idx - 1];
        }

        string answer = "";
        for (int idx = 0; idx < N; idx++) {
            int move = scanline[idx];
            char ch = s[idx];
            int pos = ((ch - 'a') + move) % 26;
            pos = (pos + 26) % 26;
            char newch = 'a' + pos;
            answer += newch;
        }

        return answer;
    }
};