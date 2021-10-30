// Time: O(N) | Space: O(N)
// N = number of elements
vector<int> solve(vector<int>& nums, int k) {
    int N = nums.size();
    vector<int> answer;
    unordered_map<int, int> hashMap;
    int count = 0;

    // for the first window, fill the map
    // and count distinct elements in this window
    for (int idx = 0; idx < k; idx++) {
        if (hashMap[nums[idx]] == 0) count += 1;
        hashMap[nums[idx]] += 1;
    }

    answer.push_back(count);
    // now for the next following windows
    // remove the first element as it is out of window
    // keep filling the elements to the map
    // keep counting the distinct elements
    for (int idx = k; idx < N; idx++) {
        if (hashMap[nums[idx - k]] == 1) count -= 1;
        hashMap[nums[idx - k]] -= 1;
        if (hashMap[nums[idx]] == 0) count += 1;
        hashMap[nums[idx]] += 1;
        answer.push_back(count);
    }

    return answer;
}