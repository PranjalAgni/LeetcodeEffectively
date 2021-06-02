#include <vector>
using namespace std;

// Time: O(log N) | Space: O(1)
int binarySearchHelper(vector<int>& array, int low, int high, int& target) {
	while(low <= high) {
		int mid = low + (high - low) / 2;
		if (array[mid] == target) return mid;
		
		if (array[mid] > target) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}
	
	return -1;
}

int binarySearch(vector<int> array, int target) {
    int low = 0;
	int high = array.size() - 1;
	return binarySearchHelper(array, low, high, target);
}
