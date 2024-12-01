// https://leetcode.com/problems/check-if-n-and-its-double-exist/

// TIME: O(n) | Space: O(n)
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int> freqMap;
        for (int& elt: arr) {
            freqMap[elt] += 1;
        }
        
        for (int& elt: arr) {
            int dup = elt * 2;
            if (dup == elt) freqMap[dup] -= 1;
            if (freqMap[dup] > 0) return true;
        }
        
        return false;
    }
};