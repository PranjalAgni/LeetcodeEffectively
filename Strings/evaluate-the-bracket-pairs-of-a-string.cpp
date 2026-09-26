// https://leetcode.com/problems/evaluate-the-bracket-pairs-of-a-string/

// Time: O(N) | Space: O(N)
class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> wordMap;
        for (vector<string>& k: knowledge) {
            wordMap[k[0]] = k[1];
        }

        int N = s.length();

        bool isKey = false;
        string current = "";
        vector<string> parts;
        for (int idx = 0; idx < N; idx++) {
            if (s[idx] == '(') {
                if (current.length() > 0) {
                    parts.push_back(current);
                    current = "";
                }
                isKey = true;
            } else if (s[idx] == ')') {
                string value = "?";
                if (wordMap.find(current) != wordMap.end()) {
                    value = wordMap[current];
                }
                
                parts.push_back(value);
                current = "";
                isKey = false;
            } else {
                current += s[idx];
            }
        }

        if (current.length() > 0) parts.push_back(current);

        string answer = "";
        for (string& p: parts) {
            answer += p;
        }

        return answer;
    }
};