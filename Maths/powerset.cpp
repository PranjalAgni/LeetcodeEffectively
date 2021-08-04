#include <vector>
using namespace std;

// Time: O(2^n) | Space: O(n*n)
vector<vector<int>> powerset(vector<int> array) {
    vector<vector<int>> subsets = {{}};
    for (int elt : array) {
        int N = subsets.size();
        for (int idx = 0; idx < N; idx++) {
            vector<int> currentSubset = subsets[idx];
            currentSubset.push_back(elt);
            subsets.push_back(currentSubset);
        }
    }

    return subsets;
}
