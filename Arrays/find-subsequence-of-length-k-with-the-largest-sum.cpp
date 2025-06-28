// https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/

// Time: O(N * k) | Space: O(1)
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int N = nums.size();
        vector<int> subsequence(k);
        for (int idx = 0; idx < k; idx++) {
            subsequence[idx] = nums[idx];
        }

        for (int idx = k; idx < N; idx++) {
            int min_index = min_element(subsequence.begin(), subsequence.end()) - subsequence.begin();
            if (subsequence[min_index] < nums[idx]) {
                subsequence.erase(subsequence.begin() + min_index);
                subsequence.push_back(nums[idx]);
            }
        }

        return subsequence;      
    }
};