// https://leetcode.com/problems/lemonade-change/

// Greedy solution
// Time: O(N) | Space: O(1)
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;
        int twenty = 0;
        
        for (int& bill: bills) {
          if (bill == 5) {
            five += 1;
          } else if (bill == 10) {
            if (five < 1) return false;
            five -= 1;
            ten += 1;
          } else if (bill == 20) {
            if ((five >= 1 && ten >= 1)) {
              five -= 1;
              ten -= 1;
              twenty += 1;
            } else if (five >= 3) {
              five -= 3;
              twenty += 1;
            } else {
              return false;
            }
          }
        }
      
        return true;
    }
};