class Solution {
public:
    // Time: O(N) | Space: O(1)
    bool checkSubarraySum(vector<int>& nums, int k) {
      unordered_map<int, int> hashMap;
      hashMap[0] = -1;
      int preSum = 0;
      int N = nums.size();
      
      for (int idx = 0; idx < N; idx++) {
        preSum += nums[idx];
        if (hashMap.find(preSum % k) != hashMap.end()) {
          int pos = hashMap[preSum % k];
          if ((idx - pos) > 1) return true;
        } else {
          hashMap[preSum % k] = idx;
        }
      }
      
      return false;
    }
};