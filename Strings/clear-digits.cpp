// https://leetcode.com/problems/clear-digits/?envType=daily-question&envId=2025-02-10

// Time: O(N) | Space: O(1)
class Solution {
private:
    bool isDigit(char& ch) {
        return ch >= '0' && ch <= '9';
    }
public:
    string clearDigits(string s) {
        string answer = "";
        int N = s.length();
        for (int idx = 0; idx < N; idx++) {
            char ch = s[idx];
            if (isDigit(ch)) {
                if (!answer.empty()) answer.pop_back();
            } else {
                answer.push_back(ch);
            }
        }
        
        return answer;
    }
};