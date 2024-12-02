// https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/

// Time: O(N) | Space: O(N)
// N = number of words
class Solution {
private:
    bool isPrefix(string& word, string& searchWord) {
        int N = word.length();
        int M = searchWord.length();
        if (M > N) return false;
        
        for (int idx = 0; idx < M; idx++) {
            if (searchWord[idx] != word[idx]) return false;
        }
        
        return true;
    }
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        vector<string> words;
        string word = "";
        int N = sentence.length();
        for (int idx = 0; idx < N; idx++) {
            char ch = sentence[idx];
            if (ch == ' ' || idx == N - 1) {
                if (idx == N - 1) word += ch;
                words.push_back(word);
                word = "";
            } else {
                word += ch;
            }
        }
        
        
        int M = words.size();
        for (int idx = 0; idx < M; idx++) {
            if (isPrefix(words[idx], searchWord)) {
                return idx + 1;
            }
        }
        
        return -1;
    }
};