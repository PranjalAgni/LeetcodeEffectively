class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> hashMap;
        for (string& word: words) {
          hashMap[word] += 1;
        }
        
        int count = 0;
        bool isFirst = true;
      
        for (string& word: words) {
          string reversedWord = word;
          reverse(reversedWord.begin(), reversedWord.end());
          if (hashMap[reversedWord] > 0) {
            hashMap[word] -= 1;
            hashMap[reversedWord] -= 1;
            count += 4;
          }
        }
      
        return count;
    }
};