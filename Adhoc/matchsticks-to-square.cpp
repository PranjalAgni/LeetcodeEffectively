// https://leetcode.com/problems/matchsticks-to-square/

class Solution {
private:
  int getSum(vector<int>& matchsticks) {
    int sum = 0;
    for (int elt: matchsticks) sum += elt;
    return sum;
  }
  
public:
    bool makesquare(vector<int>& matchsticks) {
      int value = getSum(matchsticks);
      if (value % 4 != 0) return false;
      int lengthOfSide = value / 4;
      sort(matchsticks.begin(), matchsticks.end());
      int N = matchsticks.size();
      int sidesFormed = 0;
      int start = 0;
      int end = matchsticks.size();
      int sum = 0;
      while (start < end) {
        sum += matchsticks[start];
        if (sum > lengthOfSide) return false;
        else {
          start += 1;
          if (sum == lengthOfSide) {
            sum = 0;
            sidesFormed += 1;
          }
        }
      }
      
      return sidesFormed == 4;
    }
};  


