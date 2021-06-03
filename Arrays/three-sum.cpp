#include <vector>
using namespace std;

// Time: O(N * N) | Space: O(N)
vector<vector<int>> threeNumberSum(vector<int> array, int target) {
  sort(array.begin(), array.end());
	
	int len = array.size();
	vector<vector<int>> answer;
	
	for (int idx = 0; idx < len; idx++) {
		int left = idx + 1;
		int right = len - 1;
		
		while (left < right) {
			int currSum = array[idx] + array[left] + array[right];
			if (currSum == target) {
				answer.push_back({array[idx], array[left], array[right]});
				left += 1;
				right -= 1;
				continue;
			} else if (currSum > target) {
				right -= 1;
			} else {
				left += 1;
			}
		}
	}
	

  return answer;
}
