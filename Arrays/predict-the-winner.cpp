// https://leetcode.com/problems/predict-the-winner/submissions/

// Very nice recursion + dp problem
class Solution {
private:
    // Time: O(N*N) | Space: O(N)
   int PredictWinnerRecursive(vector<int>& nums, int left, int right) {
     if (left > right) return 0;
     if (left == right) return nums[left];
     
     int currentScore = max(nums[left] + min(
       PredictWinnerRecursive(nums, left + 2, right),
       PredictWinnerRecursive(nums, left + 1, right - 1)
     ), nums[right] + min(
       PredictWinnerRecursive(nums, left + 1, right - 1),
       PredictWinnerRecursive(nums, left, right - 2)
     ));
     
     return currentScore;
   }   
public:
    bool PredictTheWinner(vector<int>& nums) {
        int N = nums.size();
        int total = 0;
        for (int& num: nums) total += num;
        int player1Score = PredictWinnerRecursive(nums, 0, N - 1);
        
        return player1Score >= total - player1Score;
    }
};