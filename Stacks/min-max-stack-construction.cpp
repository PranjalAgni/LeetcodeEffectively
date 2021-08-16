#include <bits/stdc++.h>
using namespace std;

// Feel free to add new properties and methods to the class.
// Time: O(1) | Space: O(N)
class MinMaxStack {
   public:
    stack<pair<int, pair<int, int>>> st;
    MinMaxStack() { st = stack<pair<int, pair<int, int>>>(); }
    int peek() { return st.top().first; }

    int pop() {
        int val = st.top().first;
        st.pop();
        return val;
    }

    void push(int number) {
        int minVal = number;
        int maxVal = number;
        if (!st.empty()) minVal = min(minVal, st.top().second.first);
        if (!st.empty()) maxVal = max(maxVal, st.top().second.second);
        st.push({number, {minVal, maxVal}});
    }

    int getMin() { return st.top().second.first; }

    int getMax() { return st.top().second.second; }
};
