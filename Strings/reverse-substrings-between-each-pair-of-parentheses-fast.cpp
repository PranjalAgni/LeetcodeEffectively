// https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/

// Time: O(N) | Space: O(N)
class Solution {
public:
    string reverseParentheses(string s) {
        int N = s.length();
        vector<int> pairedBrackets(N, 0);
        stack<int> st;
      
        for (int idx = 0; idx < N; idx++) {
          char ch = s[idx];
          if (ch == '(') {
            st.push(idx);
          } else if (ch == ')') {
            int pos = st.top();
            st.pop();
            pairedBrackets[pos] = idx;
            pairedBrackets[idx] = pos;
          }
        }
        
        int pos = 0;
      
        int direction = 1;
        string answer = "";
      
        while (pos < N) {
          char ch = s[pos];
          if (ch == '(' || ch == ')') {
            pos = pairedBrackets[pos];
            direction *= -1;
          } else {
            answer += ch;
          }
          
          pos += direction;
        }
  
        return answer;
    }
};