// https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful/

// Time: O(N) | Space: O(1)
// Just make pairs of 2 so length of substring will be even always and flip if pairs are not equal
class Solution {
public:
    int minChanges(string s) {
        int N = s.length();
        int answer = 0;
        for (int idx = 1; idx < N; idx+=2) {
            if (s[idx - 1] != s[idx]) {
                answer += 1;
            }
        }

        return answer;
    }
};
