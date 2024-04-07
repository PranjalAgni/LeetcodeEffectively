// https://leetcode.com/problems/valid-parenthesis-string/
class Solution {
public:
    // Time: O(N) | Space: O(1)
    bool checkValidString(string s) {
        int balance = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ')') balance -= 1;
            else balance += 1;
            
            if (balance < 0) return false;
        }
        
        if (balance == 0) return true;
        
        balance = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == '(') balance -= 1;
            else balance += 1;
            
            if (balance < 0) return false;
        }
        
        return true;
        
    }
};