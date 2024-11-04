// https://leetcode.com/problems/rotate-string/

class Solution {
public:
    bool rotateString(string s, string goal) {
        int N = s.length();
        int M = goal.length();
        if (N != M) return false;
        
        int startPos = 0;
        bool isFound = false;
        while (startPos < N) {
            if (s[startPos] == goal[0]) {
                isFound = true;
                break;
            }
            startPos += 1;
        }
        
        if (!isFound) return false;
        
        int pos = 0;
        while (startPos < N) {
            if (s[startPos] != goal[pos]) return false;
            startPos += 1;
            pos += 1;
        }
        
        int x = 0;
        while (x < startPos && pos < M) {
            if (s[x] != goal[pos]) return false;
            x += 1;
            pos += 1;
        }
        
        return true;
    }
};