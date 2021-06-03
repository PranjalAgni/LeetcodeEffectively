#include <vector>

using namespace std;

// Time: O(N) | Space: O(1)
vector<int> moveElementToEnd(vector<int> array, int toMove) {
	int start = 0;
	int end = array.size() - 1;
	
	while (start < end) {
		bool skip = false;
		if (array[start] != toMove) {
			start += 1;
			skip = true;
		}
		
		if (array[end] == toMove) {
			end -= 1;
			skip = true;
		}
		
		if (skip) continue;
		
		swap(array[start], array[end]);
		start += 1;
		end -= 1;
	}
	
  return array;
}
