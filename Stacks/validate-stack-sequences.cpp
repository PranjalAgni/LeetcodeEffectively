class Solution {
   public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int popCounter = 0;
        int len = pushed.size();

        for (int idx = 0; idx < len; idx++) {
            st.push(pushed[idx]);
            while (!st.empty() && st.top() == popped[popCounter]) {
                st.pop();
                popCounter += 1;
            }
        }

        return st.empty();
    }
};
