// https://leetcode.com/problems/kth-distinct-string-in-an-array/

// TC: O(N) | Space: O(N)
class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> freqMap;
        for (string& elt: arr) {
          freqMap[elt] += 1;
        }
        
        int pos = 0;
        int N = arr.size();
        for (int idx = 0; idx < N; idx++) {
          string elt = arr[idx];
          if (freqMap[elt] == 1) {
            pos += 1;
          }
          if (pos == k) return elt;
        }
      
        return "";
    }
};