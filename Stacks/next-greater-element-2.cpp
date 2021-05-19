// https://leetcode.com/problems/next-greater-element-ii/

class Solution {
   public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int len = nums.size();
        vector<int> ans(len, -1);

        for (int idx = 0; idx < len * 2; idx++) {
            while (!st.empty() && nums[st.top()] < nums[idx % len]) {
                ans[st.top()] = nums[idx % len];
                st.pop();
            }

            if (idx < len) st.push(idx);
        }

        return ans;
    }
};