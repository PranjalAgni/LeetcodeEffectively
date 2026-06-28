// https://leetcode.com/problems/total-waviness-of-numbers-in-range-i/

// Time: O(N) | Space: O(N)
class Solution {
private:
    int getWaviness(int num) {
        if (num < 101) return 0;
        vector<int> digits;
        while (num != 0) {
            digits.push_back(num % 10);
            num /= 10;
        }

        int N = digits.size();
        int answer = 0;

        for (int idx = N - 2; idx >= 1; idx--) {
            // check peak
            if (digits[idx] > digits[idx - 1] && digits[idx] > digits[idx + 1]) {
                answer += 1;
            }
            // check valley
            if (digits[idx] < digits[idx - 1] && digits[idx] < digits[idx + 1]) {
                answer += 1;
            }
        }

        return answer;
    }
public:
    int totalWaviness(int num1, int num2) {
        int answer = 0;
        for (int num = num1; num <= num2; num++) {
            answer += getWaviness(num);
        }

        return answer;
    }
};