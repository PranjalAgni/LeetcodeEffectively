#include <vector>
using namespace std;

// Time: O(N*N) | Space: O(1)
vector<int> bubbleSort(vector<int> array) {
  int len = array.size(); 
	
	bool isSorted = false;
	
	while(!isSorted) {
		isSorted = true;
		for (int idx = 1; idx < len; idx++) {
			if (array[idx] < array[idx - 1]) {
				swap(array[idx], array[idx - 1]);
				isSorted = false;
			}
		}
	}
	
	return array;
}
 