// https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/

class Solution {
public:
    // Time: O(N) | Space: O(1)
    bool winnerOfGame(string colors) {
        int N = colors.length();
        int aliceCount = 0;
        int bobCount = 0;
        for (int idx = 1; idx < N - 1; idx++) {
          if (colors[idx - 1] == colors[idx] && colors[idx] == colors[idx + 1]) {
            if (colors[idx] == 'A') {
              aliceCount += 1;
            } else {
              bobCount += 1;
            }
          }
        }
      
        return aliceCount > bobCount;
    }
};