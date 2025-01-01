// https://leetcode.com/problems/maximum-score-after-splitting-a-string/

// Nice string based problem for beginners
// TC: O(N*N) | Space: O(N)
class Solution {
private:
    int countTarget(string partition, char target) {
        int count = 0;
        for (char& ch: partition) {
            if (ch == target) count += 1;
        }

        return count;
    }
public:
    int maxScore(string s) {
        int N = s.length();
        int maxScore = 0;
        for (int idx = 0; idx < N - 1; idx++) {
            string left = s.substr(0, idx + 1);
            string right = s.substr(idx + 1);
            int score = countTarget(left, '0') + countTarget(right, '1');
            maxScore = max(score, maxScore);
        }

        return maxScore;
    }
};