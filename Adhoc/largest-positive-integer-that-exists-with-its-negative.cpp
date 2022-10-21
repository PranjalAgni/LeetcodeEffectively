// https://leetcode.com/contest/weekly-contest-315/problems/largest-positive-integer-that-exists-with-its-negative/

class Solution {
public:
    // Time: O(N) | Space: O(N)
    // N = number of integers
    int findMaxK(vector<int>& nums) {
        unordered_map<int, int> hashMap;
        int answer = -1;
        for (int& num: nums) {
          hashMap[num] += 1;
          if (hashMap[num * -1] > 0) answer = max(answer, abs(num));
        }
      
        return answer;
    }
};