// https://leetcode.com/problems/minimum-string-length-after-removing-substrings/
// TC: O(N) | Space: O(N)
class Solution {
public:
    int minLength(string s) {
        int N = s.length();
        stack<char> stk;
        for (int idx = 0; idx < N; idx++) {
            char ch = s[idx];
            if (ch == 'B' && stk.size() && stk.top() == 'A') stk.pop();
            else if (ch == 'D' && stk.size() && stk.top() == 'C') stk.pop();
            else stk.push(ch);
        }
        
        return stk.size();
    }
};