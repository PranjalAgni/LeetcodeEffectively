// https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/

class Solution {
private:
    vector<int> kthSortedArray(vector<int>& nums, int& k) {
      vector<int> sortedNums(nums.begin(), nums.end());
      nth_element(sortedNums.begin(), sortedNums.begin() + k - 1, sortedNums.end(), greater<int>());
      return sortedNums;
    }
public:
    // Time: O(N) | Space: O(1)
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int N = nums.size();  
        vector<int> sortedNums = kthSortedArray(nums, k);
        vector<int> answer;
        int frequency = count(sortedNums.begin(), sortedNums.begin() + k, sortedNums[k - 1]);
      
      for (int& num: nums) {
        if (num > sortedNums[k - 1] || (num == sortedNums[k - 1] && frequency-- > 0)) {
          answer.push_back(num);          
        }
      }
      
      return answer;
    }
};

