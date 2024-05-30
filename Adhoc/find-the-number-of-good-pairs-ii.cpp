// https://leetcode.com/contest/weekly-contest-399/problems/find-the-number-of-good-pairs-ii/
// Time: O(M + N*sqrt(N)) | Space: O(M)
class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int N = nums1.size();
        int M = nums2.size();
        unordered_map<int, int> freqMap;
        long long ans = 0;
        for (int& elt: nums2) {
          freqMap[elt * k] += 1;
        }
        
        for (int& elt: nums1) {
          for (int idx = 1; idx <= sqrt(elt); idx++) {
            if (elt % idx != 0) continue;
            ans += freqMap[idx];
            if (elt / idx != idx) ans += freqMap[elt / idx];
          }
        }
      
      
      
        return ans;
    }
};