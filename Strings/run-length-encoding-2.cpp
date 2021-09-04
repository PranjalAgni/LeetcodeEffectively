string solve(string s) {
    int len = s.length();
    string answer = "";
    int count = 1;

    for (int idx = 1; idx < len; idx++) {
        if (s[idx] == s[idx - 1])
            count += 1;
        else {
            answer += to_string(count) + s[idx - 1];
            count = 1;
        }
    }

    answer += to_string(count) + s[len - 1];

    return answer;
}