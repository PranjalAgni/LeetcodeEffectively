int solve(vector<int>& prices) {
    int N = prices.size();
    int profit = 0;
    if (N == 0) return profit;
    int currentBoughtAt = prices[0];
    for (int idx = 1; idx < N; idx++) {
        profit = max(profit, prices[idx] - currentBoughtAt);
        currentBoughtAt = min(currentBoughtAt, prices[idx]);
    }

    return profit;
}