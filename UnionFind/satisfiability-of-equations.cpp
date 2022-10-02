// https://leetcode.com/problems/satisfiability-of-equality-equations/

class Solution {
private:
    // Time: O(1)
    int find(vector<int>& parent, int x) {
      if (x != parent[x]) parent[x] = find(parent, parent[x]);
      return parent[x];
    }
public:
    // Time: O(N) | Space: O(26)
    bool equationsPossible(vector<string>& equations) {
        vector<int> parent(26);
        for (int idx = 0; idx < 26; idx++) {
          parent[idx] = idx;
        }
      
        for (string& equation: equations) {
          if (equation[1] == '=') {
            parent[find(parent, equation[0] - 'a')] = find(parent, equation[3] - 'a');
          }
        }
      
        for (string& equation: equations) {
          if (equation[1] == '!' && find(parent, equation[0] - 'a') == find(parent, equation[3] - 'a')) return false; 
        }
      
        return true;
    }
};