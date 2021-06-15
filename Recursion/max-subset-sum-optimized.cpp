#include <vector>
using namespace std;

#include <vector>
using namespace std;

// Time: O(N) | Space: O(1)
int maxSubsetSumNoAdjacent(vector<int> array) {
    int N = array.size();
    if (N == 0) return 0;
    int first = array[0];
    if (N == 1) return first;
    int second = max(array[0], array[1]);

    for (int idx = 2; idx < N; idx++) {
        int curr = max(first + array[idx], second);
        first = second;
        second = curr;
    }

    return second;
}
