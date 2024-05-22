// https://leetcode.com/problems/palindrome-partitioning/

// Time: O(N*2^N) | Space: O(1)
class Solution {
private:
    bool isPalindrome(string str) {
      int N = str.length();
      int start = 0;
      int end = N - 1;
      if (N == 1) return true;
      while (start <= end) {
        if (str[start] != str[end]) {
          return false;
        }
        
        start += 1;
        end -= 1;
      }
      
      return true;
    }
    
    void helper(string s, vector<string>& step, vector<vector<string>>& answer) {
      // base case
      if (s.length() == 0) {
        answer.push_back(step);
        return;
      }
      
      for (int idx = 1; idx <= s.length(); idx++) {
        string temp = s.substr(0, idx);
        if (!isPalindrome(temp)) continue;
        step.push_back(temp);
        string newstr = s.substr(idx, s.length() - idx + 1);
        
        helper(newstr, step, answer);
        step.pop_back();
      }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> answer;
        int N = s.length();
        if (N == 0) return answer;
        vector<string> step;
        helper(s, step, answer);
        return answer;
    }
};
