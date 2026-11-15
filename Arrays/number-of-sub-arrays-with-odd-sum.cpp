// https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/

// Time: O(N) | Space: O(1)
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int N = arr.size();
        long long MOD = 1e9 + 7;

        int odd = 0;
        int even = 1;
        int answer = 0;
        int sum = 0;

        for (int idx = 0; idx < N; idx++) {
            sum = (sum + arr[idx]) % 2;
            if (sum == 1) {
                answer = (answer + even) % MOD;
                odd += 1;
            } else {
                answer = (answer + odd) % MOD;
                even += 1;
            }
        }

        return answer % MOD;
    }
};
