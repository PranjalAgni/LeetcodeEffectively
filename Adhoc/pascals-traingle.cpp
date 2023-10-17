// https://leetcode.com/problems/pascals-triangle-ii/

class Solution {
public:
    // Time: O(N * N) | Space: O(N)
    // N = row index
    vector<int> getRow(int rowIndex) {
        vector<int> answer(rowIndex + 1, 1);
        for (int row = 1; row < rowIndex; row++) {
          for (int col = row; col > 0; col--) {
              answer[col] += answer[col - 1];
          }
        }
      
        return answer;
    }
};