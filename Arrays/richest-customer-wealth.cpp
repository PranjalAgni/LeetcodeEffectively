// https://leetcode.com/problems/richest-customer-wealth/

class Solution {
public:
    // Time: O(N) | Space: O(1)
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxWealth = 0;
        for (vector<int>& account: accounts) {
          int currWealth = 0;
          for (int elt: account) currWealth += elt;
          maxWealth = max(maxWealth, currWealth);
        }
      
        return maxWealth;
    }
};