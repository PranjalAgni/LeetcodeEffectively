using namespace std;

// Time: O(N) | Space: O(1)
bool isMonotonic(vector<int> array) {
	int len = array.size();
	
	if (len <= 2) return true;
	
	bool isIncreasing = true;
	bool isDecreasing = true;
	
	for (int idx = 1; idx < array.size(); idx++) {
		if (array[idx - 1] > array[idx]) {
			isIncreasing = false;
			break;
		}
	}
	
	if (isIncreasing) return true;
	
	for (int idx = 1; idx < array.size(); idx++) {
		if (array[idx - 1] < array[idx]) {
			isDecreasing = false;
			break;
		}
	}
	
	return isDecreasing;
}
