// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii

// Time: O(N) | Space: O(1)
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int N = nums.size();
        int answer = 0;
        nth_element(nums.begin(), nums.begin() + (N / 2), nums.end());
        int median = nums[N / 2];
        for (int idx = 0; idx < N; idx++) {
            answer += abs(median - nums[idx]);
        }

        return answer;      
    }
};