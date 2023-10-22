// https://leetcode.com/problems/backspace-string-compare/

class Solution {
private:
    string buildString(stack<char>& st) {
      string str = "";
      while(!st.empty()) {
        str = str + st.top();
        st.pop();
      }
      return str;
    }
    string normalizeString(string& str, int N) {
      stack<char> st;
      for (int idx = 0; idx < N; idx++) {
        if (str[idx] == '#') {
          if (!st.empty()) st.pop();
          continue;
        }
        st.push(str[idx]);
      }
      
      return buildString(st);
    }
public:
    // Time: O(N) | Space: O(N)
    bool backspaceCompare(string s, string t) {
        int sLength = s.length();
        int tLength = t.length();
        s = normalizeString(s, sLength);
        t = normalizeString(t, tLength);
        
        return s == t;
    }
};