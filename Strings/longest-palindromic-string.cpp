// https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/

// Time: O(N*len(word)) | Space: O(N)  
// N = number of words

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int N = words.size();
        unordered_map<string, int> freqMap;
        for (string& word: words) {
            freqMap[word] += 1;
        }
        
        int answer = 0;
        int middlePlacement = 0;
        for (const auto& [word, freq]: freqMap) {
            string reverseWord = word;
            reverse(reverseWord.begin(), reverseWord.end());
            
            if (word == reverseWord) {
                answer += (freq / 2) * 4;
                if (freq % 2 == 1) middlePlacement = 1;
            } else if (word < reverseWord && freqMap.count(reverseWord))  {
                // this else-if prevents counting reverseWord twice
                int a = freq;
                int b = freqMap[reverseWord];
                answer +=  min(a, b) * 4;
            }
        }


        return answer + middlePlacement * 2;
    }
};