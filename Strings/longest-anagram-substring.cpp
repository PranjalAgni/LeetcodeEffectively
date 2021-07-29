int solve(string a, string b) {
    unordered_map<char, int> hashMap;
    for (char ch : a) {
        hashMap[ch] += 1;
    }

    int ans = 0;

    for (char ch : b) {
        if (hashMap[ch]) {
            hashMap[ch] -= 1;
            ans += 1;
        }
    }

    return ans;
}