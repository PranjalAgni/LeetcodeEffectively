int solve(vector<int>& nums) {
    unordered_map<int, int> hashMap;
    for (int num : nums) {
        hashMap[num] += 1;
    }

    vector<int> freq;
    for (const auto [key, value] : hashMap) {
        freq.push_back(value);
    }

    sort(freq.begin(), freq.end());

    int N = nums.size();
    int half = N / 2;
    int ans = 0;
    if (N % 2 != 0) half += 1;

    for (int idx = freq.size() - 1; idx >= 0; idx--) {
        int value = freq[idx];
        half -= value;
        ans += 1;
        if (half <= 0) break;
    }

    return ans;
}