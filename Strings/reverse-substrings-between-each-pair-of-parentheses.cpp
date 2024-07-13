// https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/

// Time: O(N) | Space: O(N)
class Solution {
public:
    string reverseParentheses(string s) {
       int N = s.length();
       stack<char> st; 
       
       for (int idx = 0; idx < N; idx++) {
         char ch = s[idx];
         if (ch == ')') {
           string part = "";
           while (st.top() != '(') {
             part = part + st.top();
             st.pop();
           }
           st.pop();
           for (int idx = 0; idx < part.length(); idx++) {
             st.push(part[idx]);
           }
         } else {
           st.push(ch);
         }
       }
      
       string answer = "";
       while (!st.empty()) {
         char ch = st.top();
         if (ch != '(') {
           answer = ch + answer;
         }
         st.pop();
       }
      
       return answer;
    }
};

 