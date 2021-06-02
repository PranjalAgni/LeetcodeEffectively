#include <vector>
using namespace std;

// Time: O(N * logN) | Space: O(1)
int tandemBicycle(vector<int> redShirtSpeeds, vector<int> blueShirtSpeeds,
                  bool fastest) {
	
	sort(redShirtSpeeds.begin(), redShirtSpeeds.end());
	sort(blueShirtSpeeds.begin(), blueShirtSpeeds.end());
	
	int len = redShirtSpeeds.size();
	int answer = 0;
	
	if (fastest) {
		// can skip this by sorting in DESC
		reverse(redShirtSpeeds.begin(), redShirtSpeeds.end());
	}
	
	for (int idx = 0; idx < len; idx++) {
		int redSpeed = redShirtSpeeds[idx];
		int blueSpeed = blueShirtSpeeds[idx];
		answer += fastest ? max(redSpeed, blueSpeed) : max(redSpeed, blueSpeed);
	}
	
  return answer;
}
