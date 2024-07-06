// https://leetcode.com/problems/pass-the-pillow/

class Solution {
public:
    int passThePillow(int n, int time) {
        if (time <= n) return time + 1;
        time = time / n;
        return n - time - 1;
    }
};
