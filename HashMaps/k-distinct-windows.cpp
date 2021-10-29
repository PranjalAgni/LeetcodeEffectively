vector<int> solve(vector<int>& nums, int k) {
    int N = nums.size();
    vector<int> answer;
    unordered_map<int, int> hashMap;
    int count = 0;

    for (int idx = 0; idx < k; idx++) {
        if (hashMap[nums[idx]] == 0) count += 1;
        hashMap[nums[idx]] += 1;
    }

    answer.push_back(count);
    for (int idx = k; idx < N; idx++) {
        if (hashMap[nums[idx - k]] == 1) count -= 1;
        hashMap[nums[idx - k]] -= 1;
        if (hashMap[nums[idx]] == 0) count += 1;
        hashMap[nums[idx]] += 1;
        answer.push_back(count);
    }

    return answer;
}