/**
The main idea is to process all points from left to right and construct the segments gradually.

At each point, we only need to know:

Our current position.
How many segments still need to be completed.
Whether a segment is currently open.

When no segment is open, the current point can either be ignored or used as the beginning of a new segment. When a segment is open, we can either keep extending it or end it at the current point.

After starting a segment, we move to the next point because a segment must have two distinct endpoints. After ending a segment, we remain at the current point because the next segment is allowed to start from the same shared endpoint. This handles arrangements such as (0,2) and (2,3).

A segment is counted only when it is closed, so the number of remaining segments decreases when we choose its ending point, not when we start it.

Different earlier decisions can eventually produce the same current position, remaining-segment count, and open/closed status. From that moment onward, their possible future choices are identical. Memoization stores the answer for this state so it does not have to be calculated again.

Once all required segments have been completed, the arrangement is valid only if no segment remains open. If we run out of points before completing every segment, that path is invalid.
**/


// Time: O(n*k) | Space: O(n*k)
class Solution {
private:
    static const int MOD = 1'000'000'007;
    int go(int pos, int remaining, int n,  vector<vector<vector<int>>>& memo, bool isOpen) {
        // no points left
        if (pos == n) {
            return 0;
        }

        if (remaining == 0) {
            return isOpen ? 0 : 1;
        }

        if (memo[pos][remaining][isOpen] != -1) {
            return memo[pos][remaining][isOpen];
        }

        long long answer = 0;

        // current segment is currently open
        if (isOpen) {
            // dont end the segment yet
            answer += go(pos + 1, remaining, n, memo, true);
            // end the current segment so we may start a new segment further
            answer += go(pos, remaining - 1, n, memo, false);

        } else {
            // current segment is currently closed
            // we can skip this point
            answer += go(pos + 1, remaining, n, memo, false);
            // start a segment at current point
            answer += go(pos + 1, remaining, n, memo, true);
        }

        answer %= MOD;
      
        return memo[pos][remaining][isOpen] = answer;
    }
public:
    int numberOfSets(int n, int k) {
        vector<vector<vector<int>>> memo(n, vector<vector<int>>(k + 1, vector<int>(2, -1)));

        return go(0, k, n, memo, false);
    }
};
