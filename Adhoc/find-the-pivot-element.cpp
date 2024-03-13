// https://leetcode.com/problems/find-the-pivot-integer/

class Solution {
public:
    // Time: O(N) | Space: O(1)
    int pivotInteger(int n) {
        int answer = -1;
        int sum = 0;
        for (int idx = 1; idx <= n; idx++) {
            sum += idx;
            int remaining = 0;
            for (int jdx = idx; jdx <= n; jdx++) {
              remaining += jdx;
            }
          
            if (sum == remaining) return idx;
        }
      
        return answer;
    }
};