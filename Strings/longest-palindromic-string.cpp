class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int N = words.size();
        unordered_map<string, int> freqMap;
        for (int idx = 0; idx < N; idx++) {
            freqMap[words[idx]] += 1;
        }

        int answer = 0;

        for (int idx = 0; idx < N; idx++) {
            string word = words[idx];
            string reverseWord = word;
            reverse(reverseWord.begin(), reverseWord.end());
            
            if (word == reverseWord) {
                answer += freqMap[word];
                freqMap[word] = 0;
            } else {
                int a = freqMap[word];
                int b = freqMap[reverseWord];

                int minPairs = min(a, b);
                freqMap[word] -= minPairs;
                freqMap[reverseWord] -= minPairs;
                answer += minPairs;
            }
        }


        return answer * 2;
    }
};