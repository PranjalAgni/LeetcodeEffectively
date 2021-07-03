int solve(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    int N = nums.size();

    return abs(nums[N / 2] - nums[N / 2 - 1]);
}
