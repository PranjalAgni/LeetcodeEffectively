// https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/

/* 
    Result:
    Runtime: 0 ms, faster than 100.00% of C++ online submissions for Number of Students Unable to Eat Lunch.
*/

class Solution {
public:
    // Time: O(N) | Space: O(1)
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
      int square = 0;
      int circular = 0;
      int N = sandwiches.size();
      
      for (int& student: students) {
        if (student == 0) circular += 1;
        else square += 1;
      }
      
      int j = 0;
      for (j = 0; j < N; j++) {
        int type = sandwiches[j];
        if (type == 0) {
          if (circular <= 0) break;
          circular -= 1;
        } else {
          if (square <= 0) break;
          square -= 1;
        }
      }
      
      return N - j;
    }
};