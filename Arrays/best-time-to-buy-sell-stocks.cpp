// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    // Time: O(N) | Space: O(1)
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int minBuyPrice = INT_MAX;
        int currProfit = 0;
        int N = prices.size();
        for (int idx = 0; idx < N; idx++) {
          minBuyPrice = min(minBuyPrice, prices[idx]);
          currProfit = prices[idx] - minBuyPrice;
          maxProfit = max(maxProfit, currProfit);
        }
      
        return maxProfit;
    }
};