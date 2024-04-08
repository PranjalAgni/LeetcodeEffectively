// https://leetcode.com/problems/water-bottles-ii/

class Solution {
public:
    // Time: O(numBottles) | Space: O(1)
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int bottleDrank = numBottles;
        int emptyBottles = numBottles;
      
        while (emptyBottles >= numExchange) {
          bottleDrank += 1;
          emptyBottles += 1;
          emptyBottles -= numExchange;
          numExchange += 1;
        }
      
        return bottleDrank;
    }
};