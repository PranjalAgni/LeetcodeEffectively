// https://leetcode.com/problems/intersection-of-two-arrays-ii/

// Time: O(N) | Space: O(N)
// Good to solve follow up questions for this:
/*
Follow up:

1. What if the given array is already sorted? How would you optimize your algorithm?
2. What if nums1's size is small compared to nums2's size? Which algorithm is better?
3. What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
*/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> freqMap;
        for (int& elt: nums1) {
          freqMap[elt] += 1;
        }
      
        vector<int> answer;
        for (int& elt: nums2) {
          if (freqMap[elt] > 0) {
            answer.push_back(elt);
            freqMap[elt] -= 1;
          }
        }
      
        return answer;
    }
};