#include <vector>
using namespace std;

// Time: O(N * logN) | Space O(1)
bool classPhotos(vector<int> redShirtHeights, vector<int> blueShirtHeights) {
	sort(redShirtHeights.begin(), redShirtHeights.end());
	sort(blueShirtHeights.begin(), blueShirtHeights.end());
	bool isRedTaller = true;
	if (redShirtHeights[0] < blueShirtHeights[0]) isRedTaller = false;
	int len = redShirtHeights.size();
	
	for (int idx = 0; idx < len; idx++) {
		if (isRedTaller) {
			if (!(redShirtHeights[idx] > blueShirtHeights[idx])) return false;
		} else {
			if (redShirtHeights[idx] > blueShirtHeights[idx]) return false;
		}
	}
	
	return true;
	
	
  return false;
}
