class Solution {
public:
    vector<vector<char>> buildMatrix(string& text, int rows) {
      int N = text.length();
      int cols = N / rows;
      cout << N << endl;
      vector<vector<char>> matrix(rows, vector<char>(cols));
       
      int row = 0;
      int col = 0;
      
      for (int idx = 0; idx < N; idx++) {
        matrix[row][col] = text[idx];
        col += 1;
        if (col == cols) {
          row += 1;
          col = 0;
        }
      }
      
      return matrix;
    }
  
    void printMatrix(vector<vector<char>>& matrix) {
      int rows = matrix.size();
      int cols = matrix[0].size();
      for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
          cout << matrix[row][col] << " ";
        }
        cout << endl;
      }
    }
  
    string decodeCipher(vector<vector<char>>& matrix, int& rows, int& N) {
      string answer = "";
      int cols = matrix[0].size();
      int charLimit = 0;
      for (int col = 0; col < cols; col++) {    
        int startRow = 0;
        int startCol = col;
        string current = "";
        
        while (startRow < rows && startCol < cols) {
            answer.push_back(matrix[startRow][startCol]);
            charLimit += 1;  
            startRow += 1;
            startCol += 1;
        }
        
        if (charLimit == N - 1) break;
      }
 
        return answer;
    }
  
    string sanatize(string& decodedText) {
      int start = 0;
      int end = decodedText.length() - 1;
      
      while (end >= 0 && decodedText[end] == ' ') end -= 1;
      return decodedText.substr(start, end - start + 1);
    }
  
    
    // Time: O(len(encodedText)) | Space: O(rows * cols)
    string decodeCiphertext(string encodedText, int rows) {
        if (rows == 1) return encodedText;
        vector<vector<char>> matrix = buildMatrix(encodedText, rows);
        int N = encodedText.length();
        string decodedText = decodeCipher(matrix, rows, N);
        return sanatize(decodedText);
    }
};