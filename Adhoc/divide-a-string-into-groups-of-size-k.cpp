// https://leetcode.com/problems/divide-a-string-into-groups-of-size-k/

// Time: O(N) | Space: O(1)
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int N = s.length();
        while (N % k > 0) {
            s += fill;
            N = s.length();
        }
        vector<string> answer;
        string word = "";
        int left = 0;
        int right = 0;
        while (right < N) {
            word += s[right];
            if (right - left + 1 == k) {
                answer.push_back(word);
                word = "";
                left = right + 1;
            }
            right += 1;
        }
        
        return answer;
    }
};