using namespace std;

void reverseSubstring(string& str, int start, int end) {
    while (start < end) {
        swap(str[start], str[end]);
        start += 1;
        end -= 1;
    }
}

// Time: O(N) | Space: O(1)
string reverseWordsInString(string str) {
    int N = str.length();
    int start = 0;
    for (int idx = 0; idx < N; idx++) {
        if (str[idx] == ' ' || idx == N - 1) {
            int end = (idx == N - 1) ? idx : idx - 1;
            reverseSubstring(str, start, end);
            start = idx + 1;
        }
    }

    reverseSubstring(str, 0, N - 1);
    return str;
}
