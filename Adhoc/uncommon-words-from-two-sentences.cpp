// https://leetcode.com/problems/uncommon-words-from-two-sentences/

// Easy hashmap + string based problem
// Time: O(N) | Space: O(N)
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> hashMap;
        int N = s1.length();
        string word = "";
        for (int idx = 0; idx < N; idx++) {
            char ch = s1[idx];
            if (ch == ' ' || idx == N - 1) {
                if (idx == N - 1) word += ch;
                hashMap[word] += 1;
                word = "";
            } else {
                word += ch;
            }
        }
        
        int M = s2.length();
        for (int idx = 0; idx < M; idx++) {
            char ch = s2[idx];
            if (ch == ' ' || idx == M - 1) {
                if (idx == M - 1) word += ch;
                hashMap[word] += 1;
                word = "";
            } else {
                word += ch;
            }
        }
        
        vector<string> answer;
        for (const auto& it: hashMap) {
            if (it.second == 1) {
                answer.push_back(it.first);
            }
        }
        
        return answer;
        
    }
};