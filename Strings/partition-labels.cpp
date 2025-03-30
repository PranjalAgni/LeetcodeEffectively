// https://leetcode.com/problems/partition-labels/

// TC: O(NlogN) | SC: O(N)
class Solution {
private:
    vector<vector<int>> mergeIntervals(vector<vector<int>>& slots) {
        sort(slots.begin(), slots.end());
        int N = slots.size();
        int pos = 0;

        vector<vector<int>> answer;
        answer.push_back(slots[pos]);
        
        for (int idx = 1; idx < N; idx++) {
            if (answer[pos][1] >= slots[idx][0]) {
                answer[pos][1] = max(slots[idx][1], answer[pos][1]);
            } else {
                answer.push_back(slots[idx]);
                pos += 1;
            }
        }

        return answer;
    }
public:
    vector<int> partitionLabels(string s) {
        int N = s.length();
        unordered_map<char, vector<int>> hashMap;
        for (int idx = 0; idx < N; idx++) {
            char ch = s[idx];
            if (hashMap.find(ch) != hashMap.end()) {
                vector<int> v = hashMap[ch];
                hashMap[ch] = {v[0], idx};
            } else {
               hashMap[ch] = {idx, idx};
            }
        }

        vector<vector<int>> slots;

        for (const auto& it: hashMap) {
            slots.push_back(it.second);
        }

        vector<vector<int>> merged = mergeIntervals(slots);
        vector<int> answer;

        for (vector<int>& m: merged) {
            answer.push_back(m[1] - m[0] + 1);
        }

        return answer;
    }
};