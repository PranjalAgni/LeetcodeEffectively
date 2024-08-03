// https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays/?envType=daily-question&envId=2024-08-03

// TC: O(N1 + N2) | Space: O(N1 + N2)
// N1 = len(target)
// N2 = len(arr)
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> freqMap;
        for (int& elt: target) {
          freqMap[elt] += 1;
        }
      
        for (int& elt: arr) {
          freqMap[elt] -= 1;
        }
      
        for (const auto& it: freqMap) {
          if (it.second != 0) return false;
        }
      
        return true;
    }
};