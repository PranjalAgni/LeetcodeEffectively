#include <vector>
using namespace std;

// Time: O(N) | Space: O(1)
int firstDuplicateValue(vector<int> array) { 
	int len = array.size();
	
	
	for (int idx = 0; idx < len; idx++) {
		int currIdx = abs(array[idx]) - 1;
		int val = array[currIdx];
		if (val < 0) return abs(array[idx]);
		array[currIdx] = -1 * array[currIdx];
	}
	
	return -1;
}
