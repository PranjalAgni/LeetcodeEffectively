int solve(vector<int>& items, int n) {
    unordered_map<int, int> hashMap;

    for (int item : items) {
        hashMap[item] += 1;
    }

    vector<int> nums;

    for (auto const [key, value] : hashMap) {
        nums.push_back(value);
    }

    sort(nums.begin(), nums.end());

    int idx = 0;
    while (n > 0) {
        n -= nums[idx];
        if (n >= 0) idx += 1;
    }

    return nums.size() - idx;
}