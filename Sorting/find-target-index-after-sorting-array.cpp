// https://leetcode.com/contest/weekly-contest-269/problems/find-target-indices-after-sorting-array

class Solution {
   public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int N = nums.size();
        vector<int> answer;
        sort(nums.begin(), nums.end());
        bool isSeen = false;

        for (int idx = 0; idx < N; idx++) {
            if (nums[idx] == target) {
                answer.push_back(idx);
                isSeen = true;
            } else {
                if (isSeen) break;
            }
        }

        return answer;
    }
};