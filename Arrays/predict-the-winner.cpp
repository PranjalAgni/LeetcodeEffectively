// https://leetcode.com/problems/predict-the-winner/

class Solution {
public:
    // Time: O(N) | Space: O(1)
    bool PredictTheWinner(vector<int>& nums) {
        int N = nums.size();
        int left = 0;
        int right = N - 1;
        
        int player1 = 0;
        int player2 = 0;
        int turn = 0;  
      
        while (left < right) {
          int value = 0;
          if (nums[left] >= nums[right]) {
            value += nums[left];
            left += 1;
          } else {
            value += nums[right];
            right -= 1;
          }
          
          if (turn % 2 == 0) player1 += value;
          else player2 += value;
          turn += 1;
        }
      
        return player1 >= player2;
    }
};