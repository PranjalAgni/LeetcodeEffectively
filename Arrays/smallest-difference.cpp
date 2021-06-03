#include <bits/stdc++.h>
using namespace std;

// Time: O(N * logN) | Space: O(1)
vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo) {
	
	sort(arrayOne.begin(), arrayOne.end());
	sort(arrayTwo.begin(), arrayTwo.end());
	
	int lenOne = arrayOne.size();
	int lenTwo = arrayTwo.size();
	
	int ptrOne = 0;
	int ptrTwo = 0;
	
	int minDiff = INT_MAX;
	vector<int> minPair;
	
	while (ptrOne < lenOne && ptrTwo < lenTwo) {
		int diff = abs(arrayOne[ptrOne] - arrayTwo[ptrTwo]);
		if (diff == 0) {
			return {arrayOne[ptrOne], arrayTwo[ptrTwo]};
		}
		
		if (diff < minDiff) {
			minPair = {arrayOne[ptrOne], arrayTwo[ptrTwo]};
			minDiff = diff;
		}
		
		if (arrayOne[ptrOne] < arrayTwo[ptrTwo]) ptrOne += 1;
		else ptrTwo += 1;
		
	}
	
  return minPair;
}
