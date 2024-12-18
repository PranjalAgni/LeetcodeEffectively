// https://leetcode.com/problems/construct-string-with-repeat-limit/

// Time: O(NlogN) | Space: O(N)
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        int N = s.length();
        vector<int> frequency(26, 0);
        priority_queue<pair<int, int>> pq;
        // computing all the frequencies
        for (char& ch: s) {
            frequency[ch - 'a'] += 1;
        }
        
        // build pq
        for (int idx = 0; idx < 26; idx++) {
            if (frequency[idx] > 0) {
                pq.push(make_pair(idx, frequency[idx]));
            }
        }

        string answer = "";
        
        while (!pq.empty()) {
            pair<int, int> p1 = pq.top();
            pq.pop();
            char ch = char(97 + p1.first);
            int freq = p1.second;
            
            int k = min(freq, repeatLimit);
            int remaining = max(freq - repeatLimit, 0);
            
            while(k-- > 0) {
                answer += ch;
            }
            
            // means this is over now we can move to next turn
            if (remaining == 0) continue;
            
            // p1 is not exhausted yet so we can choose something from p2
            if (!pq.empty()) {
                pair<int, int> p2 = pq.top();
                pq.pop();
                char ch2 = char(97 + p2.first);
                answer += ch2;
                if (p2.second - 1 > 0) {
                    pq.push(make_pair(p2.first, p2.second - 1));
                }
            } else {
                // no p2 is present, and we can't make a valid string now so breaking
                break;
            }
            
            if (freq > repeatLimit) {
                pq.push(make_pair(p1.first, freq - repeatLimit));
            }
        }
        
        return answer;
    }
};
