class Solution {
   public:
    vector<int> computeNextPlateIndex(string& s) {
        int N = s.length();
        vector<int> next(N);
        int nextCandleIdx = N;

        for (int idx = N - 1; idx >= 0; idx--) {
            if (s[idx] == '|') nextCandleIdx = idx;
            next[idx] = nextCandleIdx;
        }
        return next;
    }

    vector<int> computePreviousPlateIndex(string& s) {
        int N = s.length();
        vector<int> previous(N);
        int previousCandleIdx = -1;

        for (int idx = 0; idx < N; idx++) {
            if (s[idx] == '|') previousCandleIdx = idx;
            previous[idx] = previousCandleIdx;
        }

        return previous;
    }

    vector<int> computePrefixCountOfStars(string& s) {
        int N = s.length();
        vector<int> prefixSum(N, 0);
        for (int idx = 0; idx < N; idx++) {
            if (idx == 0) {
                if (s[idx] == '*') prefixSum[idx] = 1;
            } else {
                prefixSum[idx] = prefixSum[idx - 1];
                if (s[idx] == '*') prefixSum[idx] += 1;
            }
        }

        return prefixSum;
    }

    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int N = s.length();
        vector<int> next = computeNextPlateIndex(s);
        vector<int> previous = computePreviousPlateIndex(s);
        vector<int> prefixCountStars = computePrefixCountOfStars(s);
        vector<int> answers;

        for (vector<int> query : queries) {
            int leftCandle = next[query[0]];
            int rightCandle = previous[query[1]];
            if (leftCandle == N || rightCandle == -1 ||
                leftCandle > rightCandle)
                answers.push_back(0);
            else {
                answers.push_back(prefixCountStars[rightCandle] -
                                  prefixCountStars[leftCandle]);
            }
        }

        return answers;
    }
};