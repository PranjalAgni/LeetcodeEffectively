// https://leetcode.com/problems/count-nice-pairs-in-an-array/
class Solution {
private:
    vector<int> getReversed(vector<int>& nums) {
      int N = nums.size();
      vector<int> reversedList(N);
      for (int idx = 0; idx < N; idx++) {
        int temp = nums[idx];
        int rev = 0;
        while (temp != 0) {
          int dig = temp % 10;
          rev = rev * 10 + dig;
          temp /= 10;
        }
        reversedList[idx] = rev;
      }
      
      return reversedList;
    }
public:
    int countNicePairs(vector<int>& nums) {
      vector<int> reversedList = getReversed(nums);
      int N = nums.size();
      int answer = 0;
      for (int idx = 0; idx < N; idx++) {
        for (int jdx = idx + 1; jdx < N; jdx++) {
            int first = nums[idx] + reversedList[jdx];
            int second = reversedList[idx] + nums[jdx];
            if (first == second) answer += 1;
        }
      }
      
      
      return answer;
    }
};