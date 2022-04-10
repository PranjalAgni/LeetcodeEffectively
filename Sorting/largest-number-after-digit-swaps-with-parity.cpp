// https://leetcode.com/contest/weekly-contest-288/problems/largest-number-after-digit-swaps-by-parity/

// Problem: https://leetcode.com/problems/largest-number-after-digit-swaps-by-parity/
// Your runtime beats 100.00 % of cpp submissions.
// https://leetcode.com/submissions/detail/677813735/


class Solution {
public:
    // TC: O(N * log(N)) | SC: O(N)
    // N = number of digits in num
    int largestInteger(int num) {
        vector<int> odd;
        vector<int> even;
        int temp = num;
        while (temp != 0) {
          int curr = temp % 10;
          if (curr % 2 == 0) {
            even.push_back(curr);
          } else {
            odd.push_back(curr);
          }
          
          temp /= 10;
        }
      
        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end());
      
        temp = num;
        int N = even.size() + odd.size();
        vector<int> answer(N);
        int evenPointer = 0;
        int oddPointer = 0;
      
        while (temp != 0) {
          int curr = temp % 10;
          if (curr % 2 == 0) {
            answer[N - 1] = even[evenPointer];
            evenPointer += 1;
          } else {
            answer[N - 1] = odd[oddPointer];            
            oddPointer += 1;
          }
          
          N -= 1;
          temp /= 10;
        }
        
        int answerValue = 0;
        for (int& elt: answer) {
          answerValue = answerValue * 10 + elt;
        }
      
        return answerValue;
    }
};

