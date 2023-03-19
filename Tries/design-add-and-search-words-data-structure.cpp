// https://leetcode.com/problems/design-add-and-search-words-data-structure/

class WordDictionary {
public:
    /** Initialize your data structure here. */
    vector<WordDictionary*> children;
    bool isEndOfWord;
    WordDictionary() {
        children = vector<WordDictionary*>(26, NULL);
        isEndOfWord = false;
    }
    
    /** Adds a word into the data structure. */
    // Time: O(m) | Space: O(26*m)
    // m = length of the word 
    void addWord(string word) {
        WordDictionary* current = this;
        for (char c: word) {
          if (current->children[c - 'a'] == NULL) {
              current->children[c - 'a'] = new WordDictionary();
          }
          
          current = current->children[c - 'a'];
        }
      
        current->isEndOfWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    // Time: O(m) | Space: O(1)
    // m = length of the word
    bool search(string word) {
        WordDictionary* current = this;
        for(int idx = 0; idx < word.length(); idx++) {
            char curr = word[idx];
            if (curr == '.') {
              for (auto child: current->children) {
                  if (child && child->search(word.substr(idx + 1))) return true;
              }
              
              return false;
            }
          
            if (current->children[curr - 'a'] == NULL) return false;
            current = current->children[curr - 'a'];
        }
      
        return current && current->isEndOfWord;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */