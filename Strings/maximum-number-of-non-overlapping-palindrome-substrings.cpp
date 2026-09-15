// https://leetcode.com/problems/maximum-number-of-non-overlapping-palindrome-substrings/

// Time: O(N) | Space: O(1)
class Solution {
private:
    void expand(string& s, int a, int b, int k, int& answer, int& used) {
        int N = s.length();
        int left = a;
        int right = b;
        bool isPalindrome = false;

        while (left >= 0 && right < N && s[left] == s[right] && left > used) {
            left -= 1;
            right += 1;
            if (right - (left + 1) >= k) {
                isPalindrome = true;
                break;
            }
            
        }

        if (isPalindrome) {
            int current = right - (left + 1);
            used = right - 1;
            answer += 1;
        }
    }
public:
    int maxPalindromes(string s, int k) {
        int N = s.length();
        int answer = 0;
        int used = -1;

        for (int idx = 0; idx < N; idx++) {
            expand(s, idx, idx, k, answer, used);
            expand(s, idx, idx + 1, k, answer, used);
        }

        return answer;
    }
};
