class MyQueue {
   public:
    /** Initialize your data structure here. */
    stack<int> stackA;
    stack<int> stackB;

    MyQueue() {
        stackA = stack<int>();
        stackB = stack<int>();
    }

    /** Push element x to the back of queue. */
    void push(int x) {
        while (!stackA.empty()) {
            int val = stackA.top();
            stackA.pop();
            stackB.push(val);
        }

        stackA.push(x);

        while (!stackB.empty()) {
            int val = stackB.top();
            stackB.pop();
            stackA.push(val);
        }
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int val = stackA.top();
        stackA.pop();
        return val;
    }

    /** Get the front element. */
    int peek() { return stackA.top(); }

    /** Returns whether the queue is empty. */
    bool empty() { return stackA.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */