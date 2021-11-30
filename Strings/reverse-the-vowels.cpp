// https://leetcode.com/problems/reverse-vowels-of-a-string

class Solution {
   public:
    bool isVowel(char ch) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            return true;

        if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
            return true;

        return false;
    }

    string reverseVowels(string s) {
        int N = s.length();
        int start = 0;
        int end = N - 1;
        while (start < end) {
            while (start < N && !isVowel(s[start])) start += 1;
            while (end >= 0 && !isVowel(s[end])) end -= 1;

            if (start < end) swap(s[start], s[end]);
            start += 1;
            end -= 1;
        }

        return s;
    }
};