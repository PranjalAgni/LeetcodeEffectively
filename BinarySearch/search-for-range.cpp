#include <bits/stdc++.h>
using namespace std;

int findIndex(vector<int>& array, int target, bool isLeft) {
    int N = array.size();
    int low = 0;
    int high = N - 1;
    int idx = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (array[mid] == target) {
            idx = mid;
            if (isLeft)
                high = mid - 1;
            else
                low = mid + 1;
        } else if (array[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return idx;
}

// Time: O(logN) || Space: O(1)
vector<int> searchForRange(vector<int> array, int target) {
    vector<int> answer = {-1, -1};
    int lowerBoundIdx = findIndex(array, target, true);
    if (lowerBoundIdx == -1) return answer;
    int upperBoundIdx = findIndex(array, target, false);
    return {lowerBoundIdx, upperBoundIdx};
}
