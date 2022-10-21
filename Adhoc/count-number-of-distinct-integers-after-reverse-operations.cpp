// https://leetcode.com/contest/weekly-contest-315/problems/count-number-of-distinct-integers-after-reverse-operations/

class Solution {
private:
    int getReverse(int num) {
      int reversedNum = 0;
      while (num != 0) {
        reversedNum = reversedNum * 10 + num % 10;
        num /= 10;
      }
      
      return reversedNum;
    }
public:
    // Time: O(N) | Space: O(N)
    int countDistinctIntegers(vector<int>& nums) {
        unordered_map<int, int> hashMap;
        int answer = 0;
      
        for (int& num: nums) {
          hashMap[num] += 1;
        }
      
        for (int& num: nums) {
          int reversedNum = getReverse(num);
          hashMap[reversedNum] += 1;

        }
      
        for (const auto& [key, value]: hashMap) {
          answer += 1;
        }
      
        return answer;
    }
};