#include <vector>
using namespace std;

int nonConstructibleChange(vector<int> coins) {
  // Write your code here.
	sort(coins.begin(), coins.end());
	int len = coins.size();
	int currentChangeCreated = 0;
	for (int idx = 0; idx < len; idx++) {
		if (coins[idx] > currentChangeCreated + 1) return currentChangeCreated + 1;
		currentChangeCreated += coins[idx];
	}
  return currentChangeCreated + 1;
}
