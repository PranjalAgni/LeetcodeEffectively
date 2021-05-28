class Solution {
   public:
    string removeOuterParentheses(string S) {
        stack<int> st;
        string answer = "";
        for (int idx = 0; idx < S.length(); idx++) {
            char ch = S[idx];
            if (ch == '(') {
                st.push(idx);
            } else {
                int openingIdx = st.top();
                st.pop();
                if ((idx - openingIdx) > 1 && st.empty()) {
                    answer += S.substr(openingIdx + 1, idx - openingIdx - 1);
                }
            }
        }

        return answer;
    }
};
