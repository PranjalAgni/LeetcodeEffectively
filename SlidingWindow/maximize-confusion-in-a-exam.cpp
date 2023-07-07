// https://leetcode.com/problems/maximize-the-confusion-of-an-exam/

class Solution {
public:
    // Time: O(N) | Space: O(1)
    int maxConsecutiveAnswers(string answerKey, int k) {
        int N = answerKey.length();
        int left = 0;
        int count = 0;
        int answer = 0;
        for (int idx = 0; idx < N; idx++) {
          if (answerKey[idx] == 'F') {
            count += 1; 
          }
          while (count > k) {
            if (answerKey[left] == 'F') {
              count -= 1;
            }
            left += 1;
          }
          answer = max(idx - left + 1, answer);
        }
      
        left = 0;
        count = 0;
        for (int idx = 0; idx < N; idx++) {
          if (answerKey[idx] == 'T') {
            count += 1;
          }
          
          while (count > k) {
            if (answerKey[left] == 'T') {
              count -= 1;
            }
            left += 1;
          }
          answer = max(idx - left + 1, answer);
        }
      
        return answer;
    }
};