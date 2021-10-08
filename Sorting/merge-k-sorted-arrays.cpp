using namespace std;

// Time: O(NM) | Space: O(N + M)
// N = Total number of arrays
// M = Total number of array elements
vector<int> mergeSortedArrays(vector<vector<int>> arrays) {
    int N = arrays.size();
    vector<int> position(N);
    vector<int> sortedArray;
    bool isSorted = false;
    while (!isSorted) {
        isSorted = true;
        int smallestIdx = -1;
        int smallestElement = INT_MAX;
        for (int idx = 0; idx < N; idx++) {
            int pos = position[idx];
            int M = arrays[idx].size();
            if (pos < M) {
                isSorted = false;
                if (arrays[idx][pos] < smallestElement) {
                    smallestElement = arrays[idx][pos];
                    smallestIdx = idx;
                }
            }
        }

        if (smallestIdx != -1) {
            position[smallestIdx] += 1;
            sortedArray.push_back(smallestElement);
        }
    }

    return sortedArray;
}
