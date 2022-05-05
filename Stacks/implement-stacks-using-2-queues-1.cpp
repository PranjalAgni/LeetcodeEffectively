// https://leetcode.com/problems/implement-stack-using-queues/

class MyStack {
   public:
    /** Initialize your data structure here. */
    queue<int> firstQueue;
    queue<int> secondQueue;
    // Time: O(1) | Space: O(N)
    MyStack() {
        firstQueue = queue<int>();
        secondQueue = queue<int>();
    }

    /** Push element x onto stack. */
    // Time: O(N) | Space: O(1)
    void push(int x) {
        while (!firstQueue.empty()) {
            int val = firstQueue.front();
            firstQueue.pop();
            secondQueue.push(val);
        }

        firstQueue.push(x);
        while (!secondQueue.empty()) {
            int val = secondQueue.front();
            secondQueue.pop();
            firstQueue.push(val);
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    // Time: O(1) | Space: O(1)
    int pop() {
        int top = firstQueue.front();
        firstQueue.pop();
        return top;
    }

    /** Get the top element. */
    int top() { return firstQueue.front(); }

    /** Returns whether the stack is empty. */
    bool empty() { return firstQueue.empty(); }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */