// https://leetcode.com/problems/number-of-valid-clock-times/

class Solution {
public:
    // Time: O(1) | Space: O(1)
    int countTime(string time) {
        char h1 = time[0];
        char h2 = time[1];
        char m1 = time[3];
        char m2 = time[4];
      
        int answer = 1;
        if (h1 == '?' && h2 == '?') answer *= 24;
        else if (h1 == '?') {
          int num = h2 - '0';
          answer *= (num < 4) ? 3 : 2;
        }
        else if (h2 == '?') answer *= (h1 == '2') ? 4 : 10;
      
        if (m1 == '?' && m2 == '?') answer *= 60;
        else if (m1 == '?') answer *= 6;
        else if (m2 == '?') answer *= 10;
      
        return answer;
    }
};