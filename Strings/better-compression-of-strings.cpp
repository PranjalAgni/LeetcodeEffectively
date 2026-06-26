// https://takeuforward.org/plus/dsa/problems/better-compression-of-string

// Time: O(N) | Space: O(N)
class Solution {
public:
    string betterCompression(string compressed) {
        vector<int> freqMap(26, 0);
        int N = compressed.length();
        int pos = 0;
        
        
        while (pos < N) {
            char ch = compressed[pos];
            int current = 0;
            pos += 1;
            while (pos < N && isdigit(compressed[pos])) {
                current = current * 10 + (compressed[pos] - '0');
                pos += 1;
            }

            freqMap[ch - 'a'] += current;

        }

        string answer = "";
        for (int idx = 0; idx < 26; idx++) {
            if (freqMap[idx] > 0) {
                char ch = 'a' + idx;
                answer += ch + to_string(freqMap[idx]);
            }
        }

        return answer;
    }
};