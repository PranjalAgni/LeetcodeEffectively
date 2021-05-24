class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        int len = heights.size();
        int maxArea = 0;
        stack<int> st;
        vector<int> nextLeftSmallest(len, -1);
        vector<int> nextRightSmallest(len, len);

        for (int idx = 0; idx < len; idx++) {
            while (!st.empty() && heights[st.top()] > heights[idx]) {
                st.pop();
            }

            if (!st.empty()) nextLeftSmallest[idx] = st.top();
            st.push(idx);
        }

        st = stack<int>();
        for (int idx = 0; idx < len; idx++) {
            while (!st.empty() && heights[idx] < heights[st.top()]) {
                nextRightSmallest[st.top()] = idx;
                st.pop();
            }
            st.push(idx);
        }

        for (int idx = 0; idx < len; idx++) {
            int width = nextRightSmallest[idx] - nextLeftSmallest[idx] - 1;
            maxArea = max(maxArea, width * heights[idx]);
        }

        return maxArea;
    }
};
