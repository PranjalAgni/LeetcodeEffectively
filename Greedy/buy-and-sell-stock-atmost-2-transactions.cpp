class Solution {
   public:
    // Time: O(N) | Space:O(N)
    int maxProfit(vector<int>& prices) {
        int N = prices.size();
        vector<int> leftProfit(N);
        vector<int> rightProfit(N);

        int minBuyPrice = INT_MAX;
        int leftMax = 0;
        int maxSellPrice = INT_MIN;
        int rightMax = 0;

        for (int idx = 0; idx < N; idx++) {
            minBuyPrice = min(minBuyPrice, prices[idx]);
            leftMax = max(leftMax, prices[idx] - minBuyPrice);
            leftProfit[idx] = leftMax;
            int jdx = N - idx - 1;
            maxSellPrice = max(maxSellPrice, prices[jdx]);
            rightMax = max(rightMax, maxSellPrice - prices[jdx]);
            rightProfit[jdx] = rightMax;
        }

        int ans = 0;
        for (int idx = 0; idx < N; idx++) {
            ans = max(ans, leftProfit[idx] + rightProfit[idx]);
        }

        return ans;
    }
};