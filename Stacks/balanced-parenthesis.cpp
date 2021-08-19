#include <bits/stdc++.h>
using namespace std;

bool balancedBrackets(string str) {
    stack<char> st;
    int N = str.length();
    for (int idx = 0; idx < N; idx++) {
        char ch = str[idx];
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (st.empty()) return false;
            char top = st.top();
            st.pop();
            if (!((top == '(' && ch == ')') || (top == '{' && ch == '}') ||
                  (top == '[' && ch == ']')))
                return false;
        }
    }

    return st.empty();
}
