// https://leetcode.com/problems/water-bottles/

// TC: O(N) | Space: O(1)SS
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int total = numBottles;
      
        while (numBottles >= numExchange) {
          total += (numBottles / numExchange);
          numBottles = (numBottles / numExchange) + (numBottles % numExchange);
         
        }
      
        return total;
    }
};
