// https://leetcode.com/problems/sum-of-even-numbers-after-queries/

class Solution {
private:
  // Time: O(N) | Space: O(N)
  unordered_map<int, int> prepareHashMap(vector<int>& nums, int& N) {
    unordered_map<int, int> hashMap;
    for (int idx = 0; idx < N; idx++) {
      hashMap[idx] = nums[idx];
    }
    
    return hashMap;
  }

  // Time: O(N) | Space: O(1)
  int getSumOfEvenNumbers(vector<int>& nums) {
    int sum = 0;
    for (int& num: nums) {
      if (num % 2 == 0) sum += num;
    }
    
    return sum;
  }
public:
    // Time: O(N) | Space: O(N)
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
      int N = nums.size();  
      unordered_map<int, int> hashMap = prepareHashMap(nums, N);
      int evenSum = getSumOfEvenNumbers(nums);
      vector<int> answer(N, 0);
      int index = 0;
      for (vector<int>& query: queries) {
        int val = query[0];
        int pos = query[1];
        int currentVal = hashMap[pos];
        if (currentVal % 2 == 0) evenSum -= currentVal;
        currentVal += val;
        if (currentVal % 2 == 0) evenSum += currentVal;
        hashMap[pos] = currentVal;
        answer[index] = evenSum;
        index += 1;
      }
      
      return answer;
    }
};