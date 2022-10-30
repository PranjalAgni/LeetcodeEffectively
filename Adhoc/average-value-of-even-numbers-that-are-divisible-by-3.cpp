// https://leetcode.com/contest/weekly-contest-317/problems/average-value-of-even-numbers-that-are-divisible-by-three/

// LC Contest #317

class Solution {
public:
    // Time: O(N) | Space: O(1)
    int averageValue(vector<int>& nums) {
        int sum = 0;
        int count = 0;
        
        for (int& elt: nums) {
          if (elt % 2 == 0 && elt % 3 == 0) {
            sum += elt;
            count += 1;
          }
        }
      
        return (sum == 0) ? sum : sum / count;
    } 
};