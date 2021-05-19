class Solution {
   public:
    bool isValid(string s) {
        int len = s.length();
        if (len % 2 != 0) return false;
        stack<char> st;
        for (int idx = 0; idx < len; idx++) {
            char ch = s[idx];
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } else {
                if (!st.size()) return false;
                if (top == '(' && ch != ')') return false;
                if (top == '{' && ch == '}') return false;
                if (top == '[' && ch == ']') return false;
                st.pop();
            }
        }

        return st.size() == 0;
    }
};