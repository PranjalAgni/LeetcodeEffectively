// https://leetcode.com/problems/continuous-subarray-sum/

// Time: O(N) | Space: O(N) 
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int N = nums.size();
        unordered_map<int, int> hashMap;
        hashMap[0] = -1;
        int preSum = 0;
        for (int idx = 0; idx < N; idx++) {
          preSum += nums[idx];
          int rem = preSum % k;
          if (hashMap.find(rem) != hashMap.end()) {
            int prevPos = hashMap[rem];
            if ((idx - prevPos) >= 2) return true;
          } else {
            hashMap[rem] = idx;
          }
        }
      
        return false;
    }
};
/**
  [Update June 10 2024]
  Theory explanation: Approach is if the mod repeats that means, 
  we have found a subarray which will be multiple of K because for the mod to repeat
  it is possible only if something which we have added divided by k is 0

  example: [23,2,4,6,7]
  index =  0  1  2  3  4
  prefix = 23 25 29 35 42
  mods =   5  1  5  5  0

  see mod=5 repeats at index 2 again
  this is because we have added 2,4 whose mod is 0 as its multiple of k


  [October 27 2022]
    a%k = b%k
    given b >= a
    d = b - a (d is difference between b and a)
    b = a + d

    a%k = (a + d)%k
    a%k = a%k + d%k
    for this to be true d%k should be 0, it means d is multiple of k
**/