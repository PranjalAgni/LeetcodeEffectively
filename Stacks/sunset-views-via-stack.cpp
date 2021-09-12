#include <bits/stdc++.h>
using namespace std;

// Time: O(N) | Space: O(N)
// This solution uses stack, and is memory intensive
// Concept is based on Next Greater Element (NGE)
vector<int> sunsetViews(vector<int> buildings, string direction) {
    if (direction == "WEST") reverse(buildings.begin(), buildings.end());
    int N = buildings.size();
    vector<int> nextGreaterElement(N);
    for (int idx = 0; idx < N; idx++) nextGreaterElement[idx] = idx;
    stack<int> st;

    for (int idx = 0; idx < N; idx++) {
        while (!st.empty() && buildings[idx] >= buildings[st.top()]) {
            nextGreaterElement[st.top()] = -1;
            st.pop();
        }

        st.push(idx);
    }

    vector<int> buildingIndexes;
    for (int elt : nextGreaterElement) {
        if (elt != -1) {
            int correctElt = (direction == "WEST") ? N - elt - 1 : elt;
            buildingIndexes.push_back(correctElt);
        }
    }

    if (direction == "WEST")
        reverse(buildingIndexes.begin(), buildingIndexes.end());
    return buildingIndexes;
}