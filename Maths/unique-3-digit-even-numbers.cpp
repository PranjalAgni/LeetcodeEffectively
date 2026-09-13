// https://leetcode.com/problems/unique-3-digit-even-numbers/

// Time: O(N) | Space: O(1)
class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);
        for (int& d: digits) {
            freq[d] += 1;
        }        

        int answer = 0;
        for (int h = 1; h <= 9; h++) {
            if (freq[h] == 0) continue;
            freq[h] -= 1;
            for (int t = 0; t <= 9; t++) {
                if (freq[t] == 0) continue;
                freq[t] -= 1;
                for (int u = 0; u <= 8; u += 2) {
                    if (freq[u] > 0) answer += 1;
                }
                freq[t] += 1;
            }
            freq[h] += 1;
        }

        return answer;
    }
};
