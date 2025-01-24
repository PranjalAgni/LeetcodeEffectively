// https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/

class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int N = words.size();
        for (int idx = 0; idx < N; idx++) {
            for (int jdx = idx + 1; jdx < N; jdx++) {
                // compare idx and jdx
                // increment answer
            }
        }

        return 42;
    }
};