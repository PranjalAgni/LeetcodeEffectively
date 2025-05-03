class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int N = tops.size();
        vector<int> topSide(7);
        vector<int> bottomSide(7);
        vector<int> sameSide(7);

        for (int idx = 0; idx < N; idx++) {
            topSide[tops[idx]] += 1;
            bottomSide[bottoms[idx]] += 1;
            if (tops[idx] == bottoms[idx]) {
                sameSide[tops[idx]] += 1;
            }
        }

        for (int idx = 1; idx < 7; idx++) {
            if (topSide[idx] + bottomSide[idx] - sameSide[idx] == N) {
                return N - max(topSide[idx], bottomSide[idx]);
            }
        }

        return -1;
    }
};