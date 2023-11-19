// https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal/?envType=daily-question

class Solution {
private:
    bool isElementsSame(vector<int>& nums, int& N) {
      int first = nums[0];
      for (int idx = 1; idx < N; idx++) {
        if (first != nums[idx]) return false;
      }
      
      return true;
    }
public:
    // Time: O(N*logN) | Space: O(N)
    int reductionOperations(vector<int>& nums) {
        int N = nums.size();
        
        vector<int> sortedNums(N);
        for (int idx = 0; idx < N; idx++) {
          sortedNums[idx] = nums[idx];
        }
      
        sort(sortedNums.begin(), sortedNums.end());
        
        unordered_map<int, int> indexMap;
        for (int idx = 0; idx < N; idx++) {
          indexMap[nums[idx]] = idx;
        }
        
        int start = 0;
        int answer = 0;
        while (!isElementsSame(nums, N) && start <= N) {
          int first = sortedNums[start];
          int second = sortedNums[start + 1];
          int targetPos = indexMap[first];
          nums[targetPos] = second;
          start += 1;
          answer += 1;
        }
      
        return answer;
        
    }
};