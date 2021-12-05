// https://leetcode.com/contest/weekly-contest-270/problems/finding-3-digit-even-numbers/

class Solution {
private:
  unordered_map<int, int> getFreqMap(vector<int>& digits) {
    unordered_map<int, int> freqMap;
    for (int elt: digits) {
      freqMap[elt] += 1;
    }
    
    return freqMap;
  }
  
  bool check(int elt, unordered_map<int, int> freqMap) {
    while (elt) {
      int digit = elt % 10;
      if (freqMap[digit] <= 0) return false;
      freqMap[digit] -= 1;
      elt /= 10;
    }
    
    return true;
  }
  
public:
    // Time: O(N) | Space: O(N)
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> answer;
        unordered_map<int, int> freqMap = getFreqMap(digits);
        for (int elt = 100; elt <= 998; elt += 2) {
          if (check(elt, freqMap)) answer.push_back(elt);  
        }
      
        return answer;
    }
};