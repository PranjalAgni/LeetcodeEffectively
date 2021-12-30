// https://leetcode.com/problems/robot-return-to-origin/

class Solution {
public:
    // Time: O(N) | Space: O(1)
    bool judgeCircle(string moves) {
        int x = 0;
        int y = 0;
      
        for (char& ch: moves) {
          if (ch == 'R') {
            y += 1;
          } else if (ch == 'L') {
            y -= 1;
          } else if (ch == 'U') {
            x -= 1;
          } else if (ch == 'D') {
            x += 1;
          }
        }
      
        return x == 0 && y == 0;
    }
};