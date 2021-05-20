class MinStack {
   public:
    /** initialize your data structure here. */
    stack<pair<int, int>> st;
    MinStack() { st = stack<pair<int, int>>(); }

    void push(int val) {
        int minVal = val;
        if (!st.empty()) {
            minVal = min(minVal, st.top().second);
        }

        st.push({val, minVal});
    }

    void pop() {
        if (!st.empty()) st.pop();
    }

    int top() { return st.top().first; }

    int getMin() { return st.top().second; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */