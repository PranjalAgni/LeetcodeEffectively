// https://leetcode.com/problems/find-the-winner-of-the-circular-game/

// Understand it
// https://leetcode.com/problems/find-the-winner-of-the-circular-game/discuss/5438775/Explanations-No-One-Will-Give-You3-Detailed-ApproachesExtremely-Simple-And-Effective
class Solution {
public:
    int findTheWinner(int n, int k) {
      int ans = 0;
      for (int idx = 1; idx <= n; idx++) {
        ans = (ans + k) % idx;
      }
      
      return ans + 1;
    }
};