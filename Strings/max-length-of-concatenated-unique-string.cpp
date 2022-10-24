// https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/

class Solution {
public:
    bool hasUniqueCharacter(string& str) {
      unordered_map<char, bool> hashMap;
      for (char ch: str) {
        if (hashMap[ch]) return false;
        hashMap[ch] = true;
      }
      
      return true;
    }
  
    void calculateMaxLength(vector<string>& arr, int currIdx, int& maxLen, string currentStr) {
      int N = arr.size();
      if (currIdx > N) return;
      if (!hasUniqueCharacter(currentStr)) return;
      if (currentStr.length() > maxLen) maxLen = currentStr.length();
      
      for (int idx = currIdx; idx < N; idx++) {
        if (hasUniqueCharacter(arr[idx])) {
          calculateMaxLength(arr, idx + 1, maxLen, currentStr + arr[idx]);
        }        
      } 
    }
    
    // Time: O(N) | Space: O(N)
    int maxLength(vector<string>& arr) {
        int maxLength = 0;
        calculateMaxLength(arr, 0, maxLength, "");
        return maxLength;
    }
};