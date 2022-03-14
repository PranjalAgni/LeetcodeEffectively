// https://leetcode.com/problems/simplify-path/

class Solution {
public:
    // Time: O(N) | Space: O(N)
    string simplifyPath(string path) {
        string answer, current;
        vector<string> stack;
        stringstream ss(path);
        while (getline(ss, current, '/')) {
          if (current == "" || current == ".") continue;
          if (current == ".." && !stack.empty()) stack.pop_back();
          else if (current != "..") stack.push_back(current);
        }
      
        for (string& str: stack) {
          answer += "/" + str;
        }
      
        return stack.empty() ? "/" : answer;
    }
};