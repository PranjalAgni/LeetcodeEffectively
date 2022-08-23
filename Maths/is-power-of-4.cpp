// https://leetcode.com/problems/power-of-four/
class Solution {
public:
    // Time: O(1) | Space: O(1)
    // Log based solution
    bool isPowerOfFour(int num) {
        if (num == 0) return false;
        double expo = log(num)/log(4);
        if(ceil(expo) == floor(expo)) return true;
        return false;
    }
};