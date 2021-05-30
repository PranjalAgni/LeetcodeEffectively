class Solution {
   public:
    bool find132pattern(vector<int>& nums) {
        int len = nums.size();
        stack<int> st;
        int s3 = INT_MIN;
        for (int idx = len - 1; idx >= 0; idx--) {
            if (s3 > nums[idx]) return true;
            while (!st.empty() && nums[idx] > st.top()) {
                s3 = max(s3, st.top());
                st.pop();
            }
            st.push(nums[idx]);
        }

        return false;
    }
};