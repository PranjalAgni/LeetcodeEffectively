class Solution {
public:
    bool isVowel(char ch) {
      return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
    
    // brute force solution
    // Time: O(N * N) | Space: O(N)
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

    // efficient solution using sliding window
    int atMost(string& word, int goal) {
      int N = word.length();
      int left = 0, right = 0;
      int answer = 0;
      unordered_map<char, int> freqMap;
      
      for (int right = 0; right < N; right++) {
        if (!isVowel(word[right])) {
          left = right + 1;
          freqMap.clear();
          continue;
        }
        
        freqMap[word[right]] += 1;
        while (freqMap.size() > goal) {
          freqMap[word[left]] -= 1;
          if (freqMap[word[left]] == 0) freqMap.erase(word[left]);
          left += 1;
        }
        
        answer += right - left + 1;
      }
      
      return answer;
    }

    // Time: O(N) | Space: O(N)
    int countVowelSubstrings(string word) {
       return atMost(word, 5) - atMost(word, 4);
    }
};