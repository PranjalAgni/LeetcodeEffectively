class Solution {
   public:
    // Time: O(N) | Space: O(1)
    int minTimeToType(string word) {
        char current = 'a';
        int minSeconds = 0;
        for (char ch : word) {
            int clockwise = abs(ch - current);
            minSeconds += 1 + min(clockwise, 26 - clockwise);
            current = ch;
        }

        return minSeconds;
    }
};
