using namespace std;

vector<int> spiralTraverse(vector<vector<int>> array) {
  int rows = array.size() - 1;
	int cols = array[0].size() - 1;
	
	int currRow = 0;
	int currCol = 0;
	
	vector<int> spiralAnswer;
	
	while (currRow <= rows && currCol <= cols) {
			for (int col = currCol; col <= cols; col++) {
				spiralAnswer.push_back(array[currRow][col]);
			}
			
			currRow += 1;
			
			for (int row = currRow; row <= rows; row++) {
				spiralAnswer.push_back(array[row][cols]);
			}
			
			cols -= 1;
		
			if (currRow > rows || currCol > cols) break;
		
			for (int col = cols; col >= currCol; col--) {
				spiralAnswer.push_back(array[rows][col]);
			}
			
			rows -= 1;
		
			for (int row = rows; row >= currRow; row--) {
				spiralAnswer.push_back(array[row][currCol]);
			}
		
			currCol += 1;
	}
	
  return spiralAnswer;
}
