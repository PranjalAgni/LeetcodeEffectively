class TrieNode {
  public:
    unordered_map<char, TrieNode*> children;
};

class Trie {
  public:
    TrieNode* root;
    char endOfWord;
  
    Trie() {
      this->root = new TrieNode();
      this->endOfWord = '$';
      //this->insert(str);
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
      
      crawlNode->children[this->endSymbol] = NULL;
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie* trie = new Trie();
        for (string& product: products) {
          trie->insert(product);
        }
    }
};