// https://leetcode.com/problems/find-closest-person/?envType=daily-question&envId=2025-09-04

class Solution {
public:
    int findClosest(int x, int y, int z) {
        int dist1 = abs(x - z);
        int dist2 = abs(y - z);
        if (dist1 == dist2) return 0;
        if (dist1 < dist2) return 1;
        return 2;
    }
};