int solve(vector<string>& words) {
    unordered_map<string, int> hashMap;
    int answer = 0;

    for (string word : words) {
        sort(word.begin(), word.end());
        if (hashMap[word] == 0) {
            answer += 1;
        }
        hashMap[word] += 1;
    }

    return answer;
}