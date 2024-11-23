// https://leetcode.com/problems/take-k-of-each-character-from-left-and-right/?envType=daily-question

// Currently wip solution
class Solution {
private:
    bool isWindowValid(vector<int>& counts, int a, int b, int c) {
        int deltaA = counts[0] - a;
        int deltaB = counts[1] - b;
        int deltaC = counts[2] - c;
        
        return deltaA >= 2 && deltaB >= 2 && deltaC >= 2;
    }
public:
    int takeCharacters(string s, int k) {
        int N = s.length();
        
        vector<int> counts(3, 0);
        for (char& ch: s) {
            counts[ch - 'a'] += 1;
        }
        
        for (int& c: counts) {
            if (c < 2) return -1;
        }
        
        int left = 0;
        int right = 0;
        
        int a_c = 0;
        int b_c = 0;
        int c_c = 0;
        
        while (right < N) {
            char ch = s[right];
            if (ch == 'a') a_c += 1;
            if (ch == 'b') b_c += 1;
            if (ch == 'c') c_c += 1;
            
            bool isValid = isWindowValid(counts, a_c, b_c, c_c);
            
            if (!isValid) {
                while (left < right) {
                    // do something here
                }
            }
            
            right += 1;
        }
    }
};