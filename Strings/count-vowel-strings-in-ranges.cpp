// https://leetcode.com/problems/count-vowel-strings-in-ranges/

// Time : O(N + Q) | Space : O(N) 
// We can just preprocess the vowels and then answer the queries in O(1) constant time
number-of-ways-to-split-arra
class Solution {
private:
    bool isVowel(char& ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    vector<int> preprocessVowels(vector<string>& words) {
        int N = words.size();
        vector<int> vowelsScore(N + 1, 0);
        vowelsScore[0] = 0;
        int pos = 1;
        for (string& word: words) {
            int last = word.length() - 1;
            if (isVowel(word[0]) && isVowel(word[last])) {
                vowelsScore[pos] = 1 + vowelsScore[pos - 1]; 
            } else {
                vowelsScore[pos] = vowelsScore[pos - 1];
            }

            pos += 1;
        }

        return vowelsScore;
    }
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int N = words.size();
        vector<int> vowelsScore = preprocessVowels(words);
        vector<int> answer;

        for (vector<int>& query: queries) {
            int first = query[0];
            int last = query[1] + 1;
            answer.push_back(vowelsScore[last] - vowelsScore[first]);
        }

        return answer;
    }
};
