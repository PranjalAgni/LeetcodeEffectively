#include <vector>
using namespace std;

unordered_map<int, bool> buildFreqMap(vector<int>& array) {
	unordered_map<int, bool> freqMap;
	for (int elt: array) {
		freqMap[elt] = true;
	}
	
	return freqMap;
}

// Time: O(N) | Space: O(1)
vector<int> largestRange(vector<int> array) {
	unordered_map<int, bool> freqMap = buildFreqMap(array);
	int N = array.size();
	int bestWindowSize = 0, bestLeft = 0, bestRight = 0;

	for (int idx = 0; idx < N; idx++) {
		int elt = array[idx];
		freqMap[elt] = false;
		int left = elt - 1;
		int right = elt + 1;
		while (freqMap[left]) {
			freqMap[left] = false;
			left -= 1;
		}
		
		while (freqMap[right]) {
			freqMap[right] = false;
			right += 1;
		}
		
		int windowSize = right - left + 1;
		if (windowSize > bestWindowSize) {
			bestWindowSize = windowSize;
			bestLeft = left;
			bestRight = right;
		}
	}
  
	return {bestLeft + 1, bestRight - 1};
}
