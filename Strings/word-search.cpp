// https://leetcode.com/problems/word-search/

class Solution {
public:
        bool isValidIndex(vector<vector<char>>& board, int row, int col) {
        int rows = board.size();
        int cols = board[0].size();
        
        if ((row >= 0 && row < rows) && (col >= 0 && col < cols)) return true;
        return false;
    }
    
    bool searchInGrid(vector<vector<char>>& board, int row, int col, string& word, int idx) {
        if (idx == word.length() - 1) return true;
        if (!isValidIndex(board, row, col) || (word[idx] != board[row][col])) return false;

        char temp = board[row][col];
        board[row][col] = '$';
        
        if (isValidIndex(board, row, col - 1) && board[row][col - 1] == word[idx + 1] && searchInGrid(board, row, col - 1, word, idx + 1)) return true;
        if (isValidIndex(board, row, col + 1) && board[row][col + 1] == word[idx + 1] && searchInGrid(board, row, col + 1, word, idx + 1)) return true;
        if (isValidIndex(board, row - 1, col) && board[row - 1][col] == word[idx + 1] && searchInGrid(board, row - 1, col, word, idx + 1)) return true;
        if (isValidIndex(board, row + 1, col) && board[row + 1][col] == word[idx + 1] && searchInGrid(board, row + 1, col, word, idx + 1)) return true;
        
        board[row][col] = temp;
        return false;
    }

    // Time: O(rows * cols) | Space: O(1)
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        char startCharacter = word[0];
      
        for (int row = 0; row < rows; row++) {
          for (int col = 0; col < cols; col++) {
            if (board[row][col] == startCharacter && searchInGrid(board, row, col, word, 0)) return true;
          }
        }
        return false;
    }
};