// https://leetcode.com/problems/minimum-number-of-buckets-required-to-collect-rainwater-from-houses/

// Time: O(N) | Space: O(1)
class Solution {
   public:
    int minimumBuckets(string street) {
        int N = street.length();
        int answer = 0;
        for (int idx = 0; idx < N; idx++) {
            char ch = street[idx];
            if (ch == 'H') {
                if (idx + 1 < N && street[idx + 1] == '.') {
                    answer += 1;
                    idx += 2;
                } else if (idx - 1 >= 0 && street[idx - 1] == '.') {
                    answer += 1;
                } else
                    return -1;
            }
        }

        return answer;
    }
};