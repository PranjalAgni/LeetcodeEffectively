using namespace std;

int minimumWaitingTime(vector<int> queries) {
	// Time O(N * logN)  | Space O(1)
	sort(queries.begin(), queries.end());
	int len = queries.size();
	int totalTime = 0;
	int currTotal = 0;
	for (int idx = 0; idx < len - 1; idx++) {
		currTotal += queries[idx];
		totalTime += currTotal;
	}
  return totalTime;
}


