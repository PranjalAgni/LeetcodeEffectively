// https://leetcode.com/problems/construct-smallest-number-from-di-string

// Time: O(N) | Space: O(N)
class Solution {
public:
    string smallestNumber(string pattern) {
        int N = pattern.length();
        stack<char> st;
        string answer = "";
        for (int idx = 0; idx <= N; idx++) {
            char ch = (char)('0' + idx + 1);
            st.push(ch);
            while (!st.empty() && (pattern[idx] == 'I' || idx == N)) {
                answer += st.top();
                st.pop();
            }
        }

        return answer;
    }
};
