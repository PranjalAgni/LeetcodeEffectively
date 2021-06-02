using namespace std;

// Time: O(N) | Space: O(1)
int firstNonRepeatingCharacter(string string) {
	vector<int> alphabets(26, 0);
	int len = string.length();
	
	for (int idx = 0; idx < len; idx++) {
		alphabets[string[idx] - 'a'] += 1;
	}
	
	for (int idx = 0; idx < len; idx++) {
		if (alphabets[string[idx] - 'a'] == 1) return idx;
	}

  return -1;
}

