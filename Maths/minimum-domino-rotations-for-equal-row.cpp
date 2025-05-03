// https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/

/**
Take example of
A = [2,1,2,4,2,2]
B = [5,2,6,2,3,2]

countA[2] = 4, as A[0] = A[2] = A[4] = A[5] = 2
countB[2] = 3, as B[1] = B[3] = B[5] = 2
same[2] = 1, as A[5] = B[5] = 2

We have countA[2] + countB[2] - same[2] = 6,
so we can make 2 in a whole row.
*/
// Time: O(N) | Space: O(N)
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