// https://leetcode.com/problems/rotate-string/

// Time: O(N*N) | Space: O(1)
// Nice space efficient technique
class Solution {
private:
    bool rotateCheck(string& s, string& goal, int rot) {
        int N = s.length();
        for (int idx = 0; idx < N; idx++) {
            if (s[idx] != goal[(idx + rot) % N]) return false;
        }
        
        return true;
    }
public:
    bool rotateString(string s, string goal) {
        int N = s.length();
        int M = goal.length();
        if (N != M) return false;
        
        for (int rot = 0; rot < N; rot++) {
            if (rotateCheck(s, goal, rot)) {
                return true;
            }
        }
        
        return false;
    }
};