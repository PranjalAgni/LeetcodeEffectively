// https://leetcode.com/problems/special-positions-in-a-binary-matrix/
class Solution {
public:
    // Time: O(rows*cols + rows + cols) | Space: O(1)
    int numSpecial(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        int answer = 0;
        for (int row = 0; row < rows; row++) {
          for (int col = 0; col < cols; col++) {
            if (mat[row][col] == 1) {
              bool isValid = true;
              int cnt = 0;
              for (int idx = 0; idx < cols; idx++) {
                if (mat[row][idx] != 0) {
                  cnt += 1;
                }
                
                if (cnt > 1) {
                  isValid = false;
                  break;
                }
              }
              
              if (!isValid) continue;
              cnt = 0;
              for (int idx = 0; idx < rows; idx++) {
                if (mat[idx][col] != 0) cnt += 1;
                if (cnt > 1) {
                  isValid = false;
                  break;
                }
              }
              if (isValid) answer += 1;
            }
          }
        }
      
        return answer;
    }
};