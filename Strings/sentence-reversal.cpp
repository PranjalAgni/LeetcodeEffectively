// Time: O(N) | Space: O(1)
// N is length of the array
vector<string> solve(vector<string>& sentence) {
    int start = 0;
    int N = sentence.size();
    int curr = 0;
    while (curr < N) {
        if (sentence[curr] == " " || curr == N - 1) {
            int end = (curr == N - 1) ? N - 1 : curr - 1;
            while (start < end) {
                swap(sentence[start], sentence[end]);
                start += 1;
                end -= 1;
            }

            start = curr + 1;
        }

        curr += 1;
    }

    start = 0;
    int end = N - 1;

    while (start < end) {
        swap(sentence[start], sentence[end]);
        start += 1;
        end -= 1;
    }

    return sentence;
}
