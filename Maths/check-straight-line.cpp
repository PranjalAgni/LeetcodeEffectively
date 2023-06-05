// https://leetcode.com/problems/check-if-it-is-a-straight-line/submissions/

// Calculating slope and comparing
class Solution {
private:
    double findSlope(int x1, int y1, int x2, int y2) {
      if (x2 - x1 == 0) return 0;
      return (double)((y2 - y1) / (x2 - x1));
    }
public:
    // Time: O(N) | Space: O(1)
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        vector<int> first = coordinates[0];
        vector<int> second = coordinates[1];
        double slope = findSlope(second[1], first[1], second[0], first[0]);
        int N = coordinates.size();
        for (int idx = 1; idx < N - 1; idx++) {
          vector<int> coordinate1 = coordinates[idx];
          vector<int> coordinate2 = coordinates[idx + 1];
          double currentSlope = findSlope(coordinate2[1], coordinate1[1], coordinate2[0], coordinate1[0]);
          if (slope != currentSlope) return false;
        }
      
        return true;
    }
};