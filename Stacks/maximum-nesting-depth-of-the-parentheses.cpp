// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/

// Time: O(N) | Space: O(N)
class Solution {
public:
    int maxDepth(string s) {
        int N = s.length();
        stack<int> st;
        int current = 0;
        int answer = 0;
        for (int idx = 0; idx < N; idx++) {
            char ch = s[idx];
            if (ch == '(') {
                current += 1;
                st.push(current);
            } else if (ch == ')') {
                int c = st.top();
                st.pop();
                answer = max(answer, c);
                current = c - 1;
            }
        }

        return answer;
    }
};