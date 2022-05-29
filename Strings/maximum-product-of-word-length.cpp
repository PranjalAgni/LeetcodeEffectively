// https://leetcode.com/problems/maximum-product-of-word-lengths/

class Solution {
private:
   bool isCommonCharPresent(vector<int>& a, vector<int>& b) {
     for (int idx = 0; idx < 26; idx++) {
       if (a[idx] && b[idx]) return true;
     }
     
     return false;
   }
  
public:
    // Time: O(N * (n + N))
    // N = size of words list
    // n = average length of a word
    int maxProduct(vector<string>& words) {
        int N = words.size();
        vector<vector<int>> bitset(N, vector<int>(26, 0));
        int ans = 0;
        for (int idx = 0; idx < N; idx++) {
          string word = words[idx];
          for (char& ch: word) {
            bitset[idx][ch - 'a'] = 1;
          }
          
          for (int jdx = 0; jdx < idx; jdx++) {
            if (!isCommonCharPresent(bitset[idx], bitset[jdx])) {
              ans = max(ans, int(words[idx].length() * words[jdx].length()));
            }
          }
        }
      
        return ans;
    }
};