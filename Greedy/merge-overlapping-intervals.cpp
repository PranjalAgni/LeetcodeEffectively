#include <vector>
using namespace std;

bool compratorFN(vector<int> A, vector<int> B) {
	return A[0] < B[0];
}

// Time: (N logN) | Space: O(N)
vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> intervals) {
  
	sort(intervals.begin(), intervals.end(), compratorFN);
	int len = intervals.size();
	
	vector<vector<int>> mergedIntervals;
	mergedIntervals.push_back(intervals[0]);
	int pos = 1;
	
	for (int idx = 1; idx < len; idx++) {
		vector<int> interval = intervals[idx];
		vector<int> current = mergedIntervals[pos - 1];
		
		if (current[1] >= interval[0] && current[1] < interval[1]) {
			mergedIntervals[pos - 1] = {current[0], interval[1]};
		} else if(current[1] < interval[0]) {
			mergedIntervals.push_back(interval);
			pos += 1;
		}
	}
	
  return mergedIntervals;
}
