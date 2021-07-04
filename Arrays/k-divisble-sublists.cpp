bool solve(vector<int>& nums, int k) {
    int N = nums.size();
    unordered_map<int, int> hashMap;
    int sum = 0;

    hashMap[sum] = -1;

    for (int idx = 0; idx < N; idx++) {
        sum += nums[idx];

        int rem = sum % k;

        if (hashMap.find(rem) != hashMap.end()) {
            int len = idx - hashMap[rem];
            if (len >= 2) return true;
        } else {
            hashMap[rem] = idx;
        }
    }

    return false;
}
