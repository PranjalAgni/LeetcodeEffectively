// https://leetcode.com/problems/score-of-a-string/
// Time: O(N) | Space: O(1)
class Solution {
public:
    int scoreOfString(string s) {
        int N = s.length();
        int answer = 0;
        for (int idx = 1; idx < N; idx++) {
          answer += abs(s[idx - 1] - s[idx]);
        }
      
        return answer;
    }
};