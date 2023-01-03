// https://leetcode.com/problems/delete-columns-to-make-sorted/

class Solution {
public:
    // Time: O(k*N) | Space: O(1)
    // k = length of a string
    // N = number of strings
    int minDeletionSize(vector<string>& strList) {
        int N = strList.size();
        int columns = strList[0].length();
        
        int deleteColumnCount = 0;
        for (int col = 0; col < columns; col++) {
          for (int idx = 1; idx < N; idx++) {
            char first = strList[idx - 1][col];
            char second = strList[idx][col];
            if (first > second) {
              deleteColumnCount += 1;
              break;
            }
          }
        }
      
        return deleteColumnCount;
    }
};