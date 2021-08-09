
int solve(string s) {
    int N = s.length();
    int ans = 0;
    vector<int> hashMap(26, 0);
    vector<int> prefix(N);
    vector<int> suffix(N);

    for (int idx = 0; idx < N; idx++) {
        int prev = (idx > 0) ? prefix[idx - 1] : 0;
        char ch = s[idx];
        if (hashMap[ch - 'a'] == 0)
            prefix[idx] += prev + 1;
        else
            prefix[idx] = prev;
        hashMap[ch - 'a'] = 1;
    }

    hashMap = vector<int>(26, 0);
    suffix[N - 1] = 0;
    for (int idx = N - 1; idx >= 1; idx--) {
        int next = suffix[idx];
        char ch = s[idx];
        if (hashMap[ch - 'a'] == 0)
            suffix[idx - 1] += next + 1;
        else
            suffix[idx - 1] = next;
        hashMap[ch - 'a'] = 1;
    }

    for (int idx = 0; idx < N; idx++) {
        if (prefix[idx] == suffix[idx]) ans += 1;
    }

    return ans;
}