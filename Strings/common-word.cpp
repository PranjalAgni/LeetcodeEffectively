string toLowerCase(string word) {
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    return word;
}

vector<string> convertStringToList(string word) {
    int N = word.length();
    vector<string> wordsList;
    string current = "";

    for (int idx = 0; idx < N; idx++) {
        char ch = word[idx];
        if (ch == ' ' || idx == N - 1) {
            if (idx == N - 1) current += ch;
            wordsList.push_back(current);
            current = "";
        } else {
            current += ch;
        }
    }

    return wordsList;
}

int solve(string s0, string s1) {
    s0 = toLowerCase(s0);
    s1 = toLowerCase(s1);
    vector<string> s0List = convertStringToList(s0);
    vector<string> s1List = convertStringToList(s1);
    unordered_map<string, int> hashMap;
    int answer = 0;

    for (string word : s0List) {
        hashMap[word] += 1;
    }

    for (string word : s1List) {
        if (hashMap[word] > 0) {
            answer += 1;
            hashMap[word] = 0;
        }
    }

    return answer;
}