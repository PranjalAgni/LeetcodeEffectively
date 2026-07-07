// https://leetcode.com/problems/concatenate-non-zero-digits-and-multiply-by-sum-i/

// Time: O(N) | Space: O(N)
class Solution {
private:
    long long getSum(int n) {
        long long sum = 0;
        while (n != 0) {
            sum += n % 10;
            n /= 10;
        }

        return sum;
    }

    long long concatenateNumber(int n) {
        long long x = 0;
        vector<int> digits;
        while (n != 0) {
            digits.push_back(n % 10);
            n /= 10;
        }

        int N = digits.size();
        for (int idx = N - 1; idx >= 0; idx--) {
            if (digits[idx] > 0) {
                x = x * 10 + digits[idx];
            }
        }

        return x;
    }
public:
    long long sumAndMultiply(int n) {
        long long sum = getSum(n);
        long long x = concatenateNumber(n);
        return x * sum;
    }
};