#include <vector>
using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum) {
    sort(array.begin(), array.end());
    int len = array.size();
    int start = 0;
    int end = len - 1;

    while (start < end) {
        int currSum = array[start] + array[end];
        if (currSum == targetSum) return {array[start], array[end]};
        if (currSum > targetSum) {
            end -= 1;
        } else {
            start += 1;
        }
    }

    return {};
}
