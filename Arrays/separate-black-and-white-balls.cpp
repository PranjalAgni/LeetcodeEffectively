// https://leetcode.com/problems/separate-black-and-white-balls/
// TC: O(N) | Space: O(1)
class Solution {
public:
    long long minimumSteps(string s) {
        long long answer = 0;
        int N = s.length();
        long long cnt = 0;
        for (int idx = 0; idx < N; idx++) {
            if (s[idx] == '1') {
                cnt += 1;
            } else {
                answer += cnt;
            }
        }
        
        return answer;
    }
};