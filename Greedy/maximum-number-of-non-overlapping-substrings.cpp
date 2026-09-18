// https://leetcode.com/problems/maximum-number-of-non-overlapping-substrings/?envType=daily-question&envId=2026-09-18

// Time: O(N*logN) | Space: O(N) 
class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int N = s.length();
        unordered_map<char, vector<int>> freqMap;

        for (int idx = 0; idx < N; idx++) {
            char ch = s[idx];
            if (freqMap.find(ch) == freqMap.end()) {
                freqMap[ch] = {idx, idx};
            }

            int start = freqMap[ch][0];
            int end = freqMap[ch][1];
            freqMap[ch] = {min(start, idx), max(end, idx)};
        }

        
        vector<vector<int>> intervals;
        for (auto& it: freqMap) {
          char ch = it.first;
          int start = freqMap[ch][0];
          int end = freqMap[ch][1];
          bool isValid = true;
          for (int jdx = start; jdx <= end; jdx++) {
            char newch = s[jdx];
            int newStart = freqMap[newch][0];
            int newEnd = freqMap[newch][1];

            if (newStart < start) {
                // invalid candidate
                isValid = false;
                break;
            }

            end = max(end, newEnd);
          }

          if (isValid) {
            intervals.push_back({start, end});
          }
        }

        // sorting by interval which is ending earlier
        sort(intervals.begin(), intervals.end(),  [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });


        int lastEnd = -1;
        vector<string> answer;
        for (vector<int>& interval: intervals) {
            if (interval[0] > lastEnd) {
                lastEnd = interval[1];
                string current = "";
                for (int idx = interval[0]; idx <= interval[1]; idx++) {
                    current += s[idx];
                }
                answer.push_back(current);
            }
        }


        return answer;
        
    }
};