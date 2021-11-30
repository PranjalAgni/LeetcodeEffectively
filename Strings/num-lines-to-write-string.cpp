// https://leetcode.com/problems/number-of-lines-to-write-string/

class Solution {
   public:
    // Time: O(N) | Space: O(1)
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int N = s.length();
        int currentWidth = 0;
        int numLines = 1;

        for (int idx = 0; idx < N; idx++) {
            int jdx = s[idx] - 97;
            currentWidth += widths[jdx];
            if (currentWidth > 100) {
                numLines += 1;
                currentWidth = widths[jdx];
            }
        }

        return {numLines, currentWidth};
    }
};