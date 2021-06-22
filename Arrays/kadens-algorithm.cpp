#include <vector>
using namespace std;

// Time: O(N) | Space: O(1)
int kadanesAlgorithm(vector<int> array) {
    int N = array.size();
    int currSum = array[0];
    int maxSum = currSum;

    for (int idx = 1; idx < N; idx++) {
        if (currSum < 0) currSum = 0;
        currSum += array[idx];
        maxSum = max(maxSum, currSum);
    }

    return maxSum;
}
