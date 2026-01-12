// https://leetcode.com/problems/minimum-time-visiting-all-points/

/**
 Proof: the time cost to travel between 2 neighboring points equals the larger value between the absolute values of the difference of respective x and y coordinates of the 2 points.

    a) Consider 2 points (x1, y1) and (x2, y2), let dx = |x1 - x2| and dy = |y1 - y2|; According to the constraints of the problem, each step at most moves 1 unit along x and/or y coordinate. Therefore, min time >= max(dx, dy);
    b) On the other hand, each step can move 1 unit along x/y coordinate to cover the distance dx/dy, whichever is greater; Therefore, min time <= max(dx, dy);
    
    Combine the above a) and b), we have max(dx, dy) <= min time <= max(dx, dy) to complete the proof.
 
 */
// Time: O(N) | Space: O(1)
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int N = points.size();
        int answer = 0;
        for (int idx = 1; idx < N; idx++) {
            answer += max(abs(points[idx][1] - points[idx - 1][1]), abs(points[idx][0] - points[idx - 1][0]));
        }

        return answer;
    }
};