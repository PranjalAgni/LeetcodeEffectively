int solve(string s0, string s1) {
    unordered_map<string, int> hashMap;
    int N = s0.length();
    string current = "";
    for (int idx = 0; idx < N; idx++) {
        char ch = s0[idx];
        if (ch == ' ' || idx == N - 1) {
            hashMap[current] += 1;
            current = "";
        } else {
            current += ch;
        }
    }

    int answer = 0;
    N = s1.length();
    for (int idx = 0; idx < N; idx++) {
        char ch = s1[idx];
        if (ch == ' ' || idx == N - 1) {
            if (hashMap[current] > 0) answer += 1;
            current = "";
        } else {
            current += ch;
        }
    }

    return answer;
}