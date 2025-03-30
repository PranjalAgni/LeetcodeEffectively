// https://leetcode.com/problems/partition-labels/

class Solution {
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

        sort(slots.begin(), slots.end());

        vector<vector<int>> merged;
        merged.push_back(slots[0]);
        int pos = 0;
        for (int idx = 1; idx < slots.size(); idx++) {
            if (merged[pos][1] >= slots[idx][0]) {
                merged[pos][1] = max(slots[idx][1], answer[pos][1]);
            } else {
                merged.push_back(intervals[idx]);
                pos += 1;
            }
        }




        for (vector<int>& slot: merged) {
            cout << slot[0] << " " << slot[1] << endl;
        }


        return {42}; 
    }
};