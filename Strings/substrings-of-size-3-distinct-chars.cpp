// https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/

class Solution {
private:
  bool isGood(string& str, int left, int right) {
    unordered_map<char, int> freqMap;
    for (int idx = left; idx <= right; idx++) {
      if (freqMap[str[idx]]) return false;
      freqMap[str[idx]] += 1;
    }
    
    return true;
  }
public:
    int countGoodSubstrings(string s) {
        int left = 0;
        int right = 0;
        int N = s.length();
        int answer = 0;
        while(right < N) {
          char ch = s[right];
          if (right >= 2) {
            if (isGood(s, left, right)) answer += 1;
            left += 1;
          }
          right += 1;
        }
      
        return answer;
    }
};