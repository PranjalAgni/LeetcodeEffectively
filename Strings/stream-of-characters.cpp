// https://leetcode.com/problems/stream-of-characters/

class Trie {
  private:
    unordered_map<char, Trie*> children;
    bool isEndOfWord;
  public:
    Trie() {
      children = unordered_map<char, Trie*>();
      isEndOfWord = false;
    }
    
    // Time: O(N) | Space: O(N)
    void insert(string& word) {
      Trie* trie = this;
      int N = word.length();
      for (char& ch: word) {
        if (!trie->children[ch]) {
          trie->children[ch] = new Trie();
        }
        trie = trie->children[ch];
      }
      
      trie->isEndOfWord = true;
    }
  
    // Time: O(N) | Space: O(1)
    bool search(deque<char>& stream) {
      Trie* trie = this;
      for (char& ch: stream) {
        if (!trie->children[ch]) return false;
        trie = trie->children[ch];
        if (trie->isEndOfWord) return true;
      }
      
      return false;
    }
};

// We reverse the word, so we can treat suffix as prefix and search in our Trie object

class StreamChecker {
public:
    Trie trie;
    deque<char> stream;
    
    // Time: O(N*N) | Space: O(N)
    StreamChecker(vector<string>& words) {
        stream = deque<char>();
        for (string& word: words) {
          reverse(word.begin(), word.end());
          trie.insert(word);
        }
    }
    
    // Time: O(N) | Space: O(1)
    bool query(char letter) {
        stream.push_front(letter);
        return trie.search(stream);
    }
};