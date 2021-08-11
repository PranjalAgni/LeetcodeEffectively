string getMapping(int digit) {
    vector<string> mappings = {"abc", "def",  "ghi", "jkl",
                               "mno", "pqrs", "tuv", "wxyz"};
    return mappings[digit - 2];
}

void backtrackCombinations(string digits, string current,
                           vector<string>& answer, int low) {
    if (current.length() == digits.length()) {
        return answer.push_back(current);
    }

    string mapping = getMapping(digits[low] - '0');

    for (int idx = 0; idx < mapping.length(); idx++) {
        current.push_back(mapping[idx]);
        backtrackCombinations(digits, current, answer, low + 1);
        current.pop_back();
    }
}
vector<string> solve(string digits) {
    vector<string> answer;
    int low = 0;
    string current = "";
    backtrackCombinations(digits, current, answer, low);
    return answer;
}