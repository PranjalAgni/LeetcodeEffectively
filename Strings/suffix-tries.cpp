class TrieNode {
  public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;
    
    TrieNode() {
      this->children = unordered_map<char, TrieNode*>();
      this->isEndOfWord = false;
    }
};

class Trie {
  private:
    TrieNode* getNodeIfExists(string& word) {
      int len = word.length();
      TrieNode* crawlNode = this->root;
      for (int idx = 0; idx < len; idx++) {
        char current = word[idx];
        if (crawlNode->children.find(current) == crawlNode->children.end()) return NULL;
        crawlNode = crawlNode->children[current];
      }
      
      return crawlNode;
    }
  
    void suggestWordsHelper(TrieNode* crawlNode, string word, vector<string>& suggestedWords) {
      if (!crawlNode) return;
      if (crawlNode->isEndOfWord) {
        suggestedWords.push_back(word);
      }
      
      for (const auto& [key, value]: crawlNode->children) {
        suggestWordsHelper(value, word + key, suggestedWords);
      }
    }
  public:
    TrieNode* root;
  
    Trie() {
      this->root = new TrieNode();
    }
  
    void insert(string& str) {
      int len = str.length();
      TrieNode* crawlNode = this->root;
      for (int idx = 0; idx < len; idx++) {
        char current = str[idx];
        if (crawlNode->children.find(current) == crawlNode->children.end()) {
          TrieNode* trieNode = new TrieNode();
          crawlNode->children[current] = trieNode;
        }
        
        crawlNode = crawlNode->children[current];
      }
      
      crawlNode->isEndOfWord = true;
    }
  
    vector<string> suggest(string& word) {
      TrieNode* crawlNode = getNodeIfExists(word);
      if (!crawlNode) return {};
      vector<string> suggestedWords;
      suggestWordsHelper(crawlNode, word, suggestedWords);
      return suggestedWords;
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie* trie = new Trie();
        for (string& product: products) {
          trie->insert(product);
        }
      
        int len = searchWord.length();
        string text = "";
        vector<vector<string>> suggestedWords;
        for (int idx = 0; idx < len; idx++) {
          text += searchWord[idx];
          vector<string> suggestWordSoFar = trie->suggest(text);
          sort(suggestWordSoFar.begin(), suggestWordSoFar.end());
          int numWords = suggestWordSoFar.size();
          if (numWords > 3) suggestWordSoFar.resize(3);
          suggestedWords.push_back(suggestWordSoFar);
        }
      
        return suggestedWords;
    }
};