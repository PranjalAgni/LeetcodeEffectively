// https://leetcode.com/problems/intersection-of-two-arrays/

class Solution {
public:
    // Time: O(N) | Space: O(N)
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, bool> hashMap;
        for (int& num: nums1) {
          hashMap[num] = true;
        }
        
        vector<int> answer;
        for (int& num: nums2) {
          if (hashMap[num]) {
            answer.push_back(num);
            hashMap[num] = false;
          }
        }
      
        return answer;
    }
};