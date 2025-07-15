// https://leetcode.com/problems/valid-word/

// Time: O(N) | Space: O(1)
class Solution {
private:
    bool isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
    }

    bool isConsonant(char ch) {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            return !isVowel(ch);
        }

        return false;
    }

public:
    bool isValid(string word) {
        int N = word.length();
        if (N < 3) return false;
        bool hasVowel = false;
        bool hasConsonant = false;

        for (char& ch: word) {
            if (!((ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))) return false;

            hasVowel = hasVowel || isVowel(ch);
            hasConsonant = hasConsonant || isConsonant(ch);
        }

        return hasVowel && hasConsonant;

    }
};