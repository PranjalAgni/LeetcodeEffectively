#include <vector>
using namespace std;

// Time: O(log N) | Space: O(1)
int shiftedBinarySearch(vector<int> array, int target) {
    int N = array.size();
    int low = 0;
    int high = N - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (array[mid] == target)
            return mid;
        else if (array[low] <= array[mid]) {
            if (target >= array[low] && target < array[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } else {
            if (target > array[mid] && target <= array[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    return -1;
}
