// https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position/

// Time: O(N) | Space: O(1)
class Solution {
public:    
    int minCostToMoveChips(vector<int>& position) {
       int odd = 0, even = 0;

       for (int& elt: position) {
          if (elt % 2 == 0) {
            even += 1;
          } else {
            odd += 1;
          }                     
       }
      
       return min(even, odd);
    }
};