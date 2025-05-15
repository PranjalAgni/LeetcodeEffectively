// https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-i/?envType=daily-question&envId=2025-05-15

// Time: O(N) | Space: O(1)
class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int N = words.size();
        int start = 0;
        int end = 0;
        int maxLength = 0;
        int finalStart = 0;
        int finalEnd = 0;

        for (int idx = 1; idx < N; idx++) {
            string word = words[idx];
            int groupId = groups[idx];
            if (groupId == groups[idx - 1]) {
                // its closing here
                int currentLength = idx - start;
                if (currentLength > maxLength) {
                    maxLength = currentLength;
                    finalStart = start;
                    finalEnd = idx - 1;
                }

                start = idx;
            }
        }

        vector<string> answer;
        while(finalStart <= finalEnd) {
            answer.push_back(words[finalStart]);
            finalStart += 1;
        }

        
        return answer;
    }
};