// Time: O(N * M) | Space: O(N)
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int N = grid.size();
        int M = grid[0].size();

        set<pair<int, int>> sp;

        for (int idx = 0; idx < N; idx++) {
            set<pair<int, int>> current;
            for (int jdx = 0; jdx < M; jdx++) {
                if (grid[idx][jdx] == 1) {
                    current.insert(make_pair(idx, jdx));
                }
            }

            if (current.size() >= 2) {
                sp.insert(current.begin(), current.end());
            }
        }

        for (int jdx = 0; jdx < M; jdx++) {
            set<pair<int, int>> current;
            for (int idx = 0; idx < N; idx++) {
                if (grid[idx][jdx] == 1) {
                    current.insert(make_pair(idx, jdx));
                }
            }

            if (current.size() >= 2) {
                sp.insert(current.begin(), current.end());
            }
        }

        return sp.size();
    }
};