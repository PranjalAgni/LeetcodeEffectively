class Solution {
public:
    bool isVowel(char ch) {
      return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
    
    // brute force solution
    int countVowelSubstrings(string word) {
        int N = word.length();
        int answer = 0;
        unordered_map<char, int> freqMap;
        for (int idx = 0; idx < N; idx++) {
          freqMap.clear();
          for (int jdx = idx; jdx < N && isVowel(word[jdx]); jdx++) {
            freqMap[word[jdx]] += 1;
            if (freqMap.size() == 5) answer += 1;
          }
        }
        
        return answer;
    }
};