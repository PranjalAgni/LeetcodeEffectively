// https://leetcode.com/problems/number-complement/

// Straight forward non bit manipulation solution
// Time: O(N) | Space: O(N)
class Solution {
public:
    int findComplement(int num) {
      vector<int> temp; 
		  // convert to binary representation
      while( num != 0 ){
          temp.push_back(num % 2);
          num /= 2;
      }
      
      int N = temp.size();
      for (int idx = 0; idx < N; idx++) {
        if (temp[idx] == 1) temp[idx] = 0;
        else temp[idx] = 1;
      }
      
      
      int answer = 0;
      for (int idx = N - 1; idx >= 0; idx--) {
        answer = answer * 2 + temp[idx];
      }
     
      return answer;
    }
};