// https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/

class Solution {
private:
    bool isPrefix(int num1, int num2) {
      int start1 = 10;
      int start2 = 10;
      while (start1 < num1 || start2 < num2) {
        if (start1 < num1) {
          start1 *= 10;
        }
        
        if (start2 < num2) {
          start2 *= 10;
        }
      }
      
      if (start1 != 10) start1 /= 10;
      if (start2 != 10) start2 /= 10;
      
       return (num1 % start1) == (num2 % start2);
    }
  
  
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int answer = 0;
        for (int& num1: arr1) {
          for (int& num2: arr2) {
            if (isPrefix(num1, num2)) answer += 1;
          }
        }
      
        return answer;
    }
};