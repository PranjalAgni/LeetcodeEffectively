// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/

class Solution {
public:
    // Time: O(N) | Space: O(N)
    string removeDuplicates(string s, int k) {
       vector<pair<int, char>> stack = {{0, '#'}};
        for (char c: s) {
            if (stack.back().second != c) {
                stack.push_back({1, c});
            } else if (++stack.back().first == k)
                stack.pop_back();
        }
        string res;
        for (auto & p : stack) {
            res.append(p.first, p.second);
        }
      
        return res;
    }
};