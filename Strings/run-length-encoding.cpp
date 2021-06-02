using namespace std;

string encodeChunk(char ch, int digit) {
	string encoded = "";
	char chDig = '0' + digit;
	encoded += chDig;
	encoded += ch;
	return encoded;
}

// Time: O(N) | Space: O(1)
string runLengthEncoding(string str) {
	int currentCount = 1;
	char currentChar = str[0];
	string encodedStr = "";
	int len = str.length();
	
	for (int idx = 1; idx <= len; idx++) {
			if (idx != len && str[idx] == str[idx - 1]) {
				currentCount += 1;
				currentChar = str[idx];
				if (currentCount == 9) {
					encodedStr += encodeChunk(currentChar, 9);
					currentCount = 0;
				}
			} else {
				if (currentCount > 0) encodedStr += encodeChunk(currentChar, currentCount);
				currentCount = 1;
				currentChar = str[idx];
			}
	}
	
  return encodedStr;
}
