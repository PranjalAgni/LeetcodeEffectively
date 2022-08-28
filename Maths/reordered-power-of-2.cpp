// https://leetcode.com/problems/reordered-power-of-2/

class Solution {
public:
    // Time: O(N*logN) | Space: O(N)
    // N = number of digits
    bool reorderedPowerOf2(int n) {
        string numStr = to_string(n);
        sort(numStr.begin(), numStr.end());
        
        for (int idx = 0; idx < 31; idx++) {
          int currentPowerOf2 = (1 << idx);
          string currentPowerOf2Str = to_string(currentPowerOf2);
          sort(currentPowerOf2Str.begin(), currentPowerOf2Str.end());
          if (numStr == currentPowerOf2Str) return true;
        }
      
        return false;
    }
};