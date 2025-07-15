class Solution {
public:
    bool isValid(string word) {
        int N = word.length();
        if (N < 3) return false;
        for (char& ch: word) {
            if (!((ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))) return false;
        }

        return true;

    }
};