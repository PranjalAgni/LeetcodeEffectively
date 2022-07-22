// https://leetcode.com/problems/number-of-matching-subsequences/

class Solution {
public:
    // Time: O(words.length() + s.length() * words.length()) | Space: O(s.length())
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char, vector<string>> hashMap;
        for (string& word: words) {
            char firstChar = word[0];
            hashMap[firstChar].push_back(word);
        }
        
        int answer = 0;
        for (char& letter: s) {
            vector<string> wordStartingWithLetter = hashMap[letter];
            hashMap[letter] = {};
            for (string& currentWord: wordStartingWithLetter) {
                string newWord = currentWord.substr(1);
                if (newWord.length() > 0) {
                   hashMap[newWord[0]].push_back(newWord); 
                } else {
                    answer += 1;                     
                }              
            }
        }
        
        return answer;
    }
};