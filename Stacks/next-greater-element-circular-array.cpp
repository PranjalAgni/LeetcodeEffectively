#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int> array) {
    stack<int> st;
    int N = array.size();
    vector<int> answer(N, -1);

    for (int idx = 0; idx < 2 * N; idx++) {
        int wrappedIdx = idx % N;
        while (!st.empty() && array[wrappedIdx] > array[st.top()]) {
            answer[st.top()] = array[wrappedIdx];
            st.pop();
        }

        if (idx < N) st.push(idx);
    }

    return answer;
}
