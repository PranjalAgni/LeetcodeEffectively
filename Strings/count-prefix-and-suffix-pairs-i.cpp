// https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/

// Time: O(N^2) | Space: O(1)

class Solution {
private:
    bool checkPrefix(string& a, string& b) {
        int N = a.length();
        int M = b.length();
        if (N > M) return false;

        for (int idx = 0; idx < N; idx++) {
            if (a[idx] != b[idx]) return false;
        }

        return true;
    }

    bool checkSuffix(string& a, string& b) {
        int N = a.length();
        int M = b.length();
        if (N > M) return false;

        for (int pos = 0, idx = M - N; idx < M; pos++, idx++) {
            if (a[pos] != b[idx]) return false;
        }

        return true;
    }
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int N = words.size();
        int answer = 0;
        for (int idx = 0; idx < N; idx++) {
            string a = words[idx];
            for (int jdx = idx + 1; jdx < N; jdx++) {
                string b = words[jdx];
                if (checkPrefix(a, b) && checkSuffix(a, b)) answer += 1;
            }
        }

        return answer;
    }
};