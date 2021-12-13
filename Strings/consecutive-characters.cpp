// https://leetcode.com/problems/consecutive-characters/

class Solution {
public:
    // Time: O(N) | Space: O(1)
    int maxPower(string s) {
        int maxPower = 1;
        int currPower = 1;
        int N = s.length();
        for (int idx = 1; idx < N; idx++) {
          if (s[idx] == s[idx - 1]) currPower += 1;
          else {
            maxPower = max(maxPower, currPower);
            currPower = 1;
          }
        }
        maxPower = max(maxPower, currPower);
        return maxPower;
    }
};