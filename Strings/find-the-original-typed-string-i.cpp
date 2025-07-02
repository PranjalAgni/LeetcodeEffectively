// https://leetcode.com/problems/find-the-original-typed-string-i/

// Time: O(N) | Space: O(1)
class Solution {
public:
    int possibleStringCount(string word) {
        int N = word.length();
        int answer = 1;
        int count = 1;

        for (int idx = 1; idx < N; idx++) {
            if (word[idx - 1] == word[idx]) {
                count += 1;
            } else {
                answer += (count - 1);
                count = 1;
            }
        }

        if (count > 1) {
            answer += count - 1;
        }

        return answer;
    }
};