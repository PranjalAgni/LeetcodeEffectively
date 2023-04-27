// https://leetcode.com/problems/bulb-switcher/

class Solution {
public:
    int bulbSwitch(int n) {
      if (n == 0 || n == 1) return n;
      vector<int> bulbs(n + 1, 1);
      for (int idx = 2; idx <= n; idx++) {
        int bulbIndex = idx;
        while (bulbIndex <= n) {
          bulbs[bulbIndex] = 1 - bulbs[bulbIndex];
          bulbIndex += idx;
        }
      }
      
      int answer = -1;
      for (int& bulbState: bulbs) {
        if (bulbState) answer += 1;
      }
      
      return answer;
    }
};