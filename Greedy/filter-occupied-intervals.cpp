// https://leetcode.com/problems/filter-occupied-intervals/

// Time: O(N*logN) | Space: O(N)
class Solution {
private:
    vector<vector<int>> excludeIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        int N = occupiedIntervals.size();
        vector<vector<int>> remaining;
        for (int idx = 0; idx < N; idx++) {
            int left = occupiedIntervals[idx][0];
            int right = occupiedIntervals[idx][1];
            if (left < freeStart) {
                int newLeft = left;
                int newRight = min(right, freeStart - 1);
                if (newLeft <= newRight) {
                    remaining.push_back({newLeft, newRight});
                }
            }

            if (right > freeEnd) {
                int newLeft = max(freeEnd + 1, left);
                int newRight = right;
                 if (newLeft <= newRight) {
                    remaining.push_back({newLeft, newRight});
                }
            }            
        }

        return remaining;
    }
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {

        vector<vector<int>> remaining = excludeIntervals(occupiedIntervals, freeStart, freeEnd);

        // if remaining becomes empty we can fix
        if (remaining.empty()) return {};

        sort(remaining.begin(), remaining.end());
        int N = remaining.size();
        vector<vector<int>> mergedIntervals;
        mergedIntervals.push_back(remaining[0]);
        int pos = 0;
        for (int idx = 1; idx < N; idx++) {
            // touch
            if (remaining[idx][0] == mergedIntervals[pos][1] + 1) {
                mergedIntervals[pos][0] = min(mergedIntervals[pos][0], remaining[idx][0]);
                
                mergedIntervals[pos][1] = max(mergedIntervals[pos][1], remaining[idx][1]);
            }

            // overlap
            if (mergedIntervals[pos][1] >= remaining[idx][0]) {
                mergedIntervals[pos][1] = max(mergedIntervals[pos][1], remaining[idx][1]);
            } else {
                mergedIntervals.push_back(remaining[idx]);
                pos += 1;
            }
        }

        return mergedIntervals;
        
    }
};