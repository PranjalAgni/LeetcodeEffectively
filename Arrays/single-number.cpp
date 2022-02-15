// https://leetcode.com/problems/single-number/

class Solution {
public:
    // Time: O(N) | Space: O(1)
    int singleNumber(vector<int>& nums) {
        int answer = 0;
        for (int& elt: nums) {
          answer = answer ^ elt;
        }
              
        return answer;
    }
};