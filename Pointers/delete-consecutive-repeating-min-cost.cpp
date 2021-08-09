int solve(string s, vector<int>& nums) {
    int N = nums.size();
    int ans = 0;
    int sumCost = 0;
    int maxCost = 0;

    for (int idx = 0; idx < N; idx++) {
        if (idx > 0 && s[idx] != s[idx - 1]) {
            ans += sumCost - maxCost;
            sumCost = 0;
            maxCost = 0;
        }

        sumCost += nums[idx];
        maxCost = max(maxCost, nums[idx]);
    }
    
    ans += sumCost - maxCost;
    return ans;
}