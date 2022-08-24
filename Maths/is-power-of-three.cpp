// https://leetcode.com/problems/power-of-three/

class Solution {
public:
    // Time: O(1) | Space: O(1)
    // 1162261467=3^19. 3^20 is bigger than int.
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        return ((int)pow(3,19)) % n == 0;
    }
};