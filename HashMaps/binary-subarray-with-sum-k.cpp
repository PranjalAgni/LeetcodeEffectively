// https://leetcode.com/problems/binary-subarrays-with-sum/

class Solution {
   public:
    // Time: O(N) | Space: O(N)
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int N = nums.size();
        unordered_map<int, int> hashMap;
        int currSum = 0;
        int answer = 0;

        for (int idx = 0; idx < N; idx++) {
            currSum += nums[idx];
            if (currSum == goal) answer += 1;
            if (hashMap.find(currSum - goal) != hashMap.end())
                answer += hashMap[currSum - goal];
            hashMap[currSum] += 1;
        }

        return answer;
    }
};