class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int N = nums.size();
        int left = 0;
        int right = 0;
        int count0 = 0;
        int count1 = 0;
        int maxLength = 0;
      
        while (right < N) {
            if (nums[right] == 0) count0 += 1;
            else count1 += 1;
            if (count0 == count1) {
              maxLength = max(maxLength, right - left + 1);
            }
            right += 1;
        }
      
       while (left < right) {
         if (nums[left] == 0) count0 -= 1;
         else count1 -= 1;
         left += 1;
         if (count0 == count1) {
           maxLength = max(maxLength, right - left);
         }
       }
      
       return maxLength; 
    }
};