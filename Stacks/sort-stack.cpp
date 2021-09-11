#include <vector>
using namespace std;

// Time: O(N * N) | Space: O(1)
// No auxillary space
// Basically we do follow this:
// 1. Pop out all the elements out of stack
// 2. Check if the current top element is less than the element at the top of
// stack
// 3. If condition 2 is true, insert the top element else pop the current top
// element in the stack and insert the current top element in stack
void insertInCorrectPosition(vector<int>& stack, int value) {
    // insert element if stack is empty or top element in stack is less than
    // current element
    if (stack.size() == 0 || stack.back() <= value) {
        stack.push_back(value);
        return;
    }

    int top = stack.back();
    stack.pop_back();
    insertInCorrectPosition(stack, value);
    stack.push_back(top);
}

vector<int> sortStack(vector<int>& stack) {
    if (stack.size() == 0) return stack;
    int top = stack.back();
    stack.pop_back();
    sortStack(stack);
    insertInCorrectPosition(stack, top);
    return stack;
}
