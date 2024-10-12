// https://leetcode.com/problems/maximum-width-ramp/submissions/
// Solve more problems
// Good problem to solve based on decreasing stack concept
// TC: O(N) | Space: O(N)
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int N = nums.size();
        // build a decreasing stack
        
        stack<int> st;
        for (int idx = 0; idx < N; idx++) {
            if (st.empty() || nums[st.top()] > nums[idx]) {
                st.push(idx);
            }
        }
        
        int maxWidth = 0;
        
        for (int idx = N - 1; idx >= 0; idx--) {
            while (!st.empty() && nums[st.top()] <= nums[idx]) {
                maxWidth = max(maxWidth, idx - st.top());
                st.pop();
            }
        }
        
        
        return maxWidth;
    }
};
