int solve(vector<string>& words) {
    int N = words.size();
    for (int idx = 0; idx < N; idx++) {
        string word = words[idx];
        sort(word.begin(), word.end());
        words[idx] = word;
    }

    unordered_map<string, int> hashMap;
    int ans = 0;

    for (int idx = 0; idx < N; idx++) {
        string word = words[idx];
        if (hashMap.find(word) != hashMap.end()) {
            hashMap[word] += 1;
        } else {
            hashMap[word] = 1;
        }

        ans = max(ans, hashMap[word]);
    }
    return ans;
}