using namespace std;

// Time: O(N) | Space: O(1)
int longestPeak(vector<int> array) {
  int len = array.size();
	if (len < 3) return 0;
	int maxPeek = 0;
	for (int idx = 1; idx < len; idx++) {
		int left = idx;
		int right = idx;
		bool isPeekFormed = false;
		while(left > 0 && array[left] > array[left - 1]) {
			left -= 1;
			isPeekFormed = true;
		}
		
		if(!isPeekFormed) continue;
		isPeekFormed = false;
		while (right < len - 1 && array[right] > array[right + 1]) {
			right += 1;
			isPeekFormed = true;
		}
		
		int numElement = right - left + 1;
		if (numElement >= 3 && isPeekFormed) {
			maxPeek = max(maxPeek, numElement);
		}
		idx = right;
	}
	
  return maxPeek;
}
