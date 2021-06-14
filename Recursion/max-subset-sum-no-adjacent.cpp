#include <vector>
using namespace std;

int maxSubsetSumHelper(vector<int> array, int pos) {
    if (pos >= array.size()) return 0;
    int withoutCurrent = maxSubsetSumHelper(array, pos + 1);
    int withCurrent = array[pos] + maxSubsetSumHelper(array, pos + 2);
    return max(withoutCurrent, withCurrent);
}

int maxSubsetSumNoAdjacent(vector<int> array) {
    int answer = maxSubsetSumHelper(array, 0);
    return answer;
}
