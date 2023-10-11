// https://leetcode.com/contest/weekly-contest-365/problems/minimum-size-subarray-in-infinite-array/

class Solution {
private:
    int getSum(vector<int>& nums) {
      int sum = 0;
      for (int& elt: nums) {
        sum += elt;
      }
      
      return sum;
    }
    
    int getNormalizedIndex(int idx, int& N) {
      return idx % N;
    }
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        int N = nums.size();
        int sum = getSum(nums);
        if (target % sum == 0) return N * (target / sum);
        int blockSize = target / sum + 2;
        int left = 0;
        int right = 0;
        int totalSize = (N * blockSize);
        int currentSum = 0;
        int answer = INT_MAX;
        while (right < totalSize) {
          currentSum += nums[getNormalizedIndex(right, N)];
          while (currentSum > target) {
            currentSum -= nums[getNormalizedIndex(left, N)];
            left += 1;
          }
          
          if (currentSum == target) {
            answer = min(answer, right - left + 1);
          }
          
          right += 1;
        }
      
        return answer == INT_MAX ? -1 : answer;
        
    }
};