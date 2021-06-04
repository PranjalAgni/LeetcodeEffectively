#include <vector>

using namespace std;

vector<int> arrayOfProducts(vector<int> array) {
  int len = array.size();
	vector<int> output(len, 0);
	int product = 1;
	int numZero = 0;
	for (int idx = 0; idx < len; idx++) {
		if (array[idx] == 0) {
			numZero += 1;
			continue;
		}
		
		product *= array[idx];
	}

	// if more than 1 zero then whole output is 0
	if (numZero > 1) return output;
	
	for(int idx = 0; idx < len; idx++) {
		output[idx] = (array[idx] == 0) ? product : (numZero > 0) ? 0 : (product / array[idx]);
	}
	
  return output;
}
