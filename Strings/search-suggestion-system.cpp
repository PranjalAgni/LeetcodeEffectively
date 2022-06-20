// https://leetcode.com/problems/search-suggestions-system/

/**
Idea: Trie + Sort solution
Steps: 

1. Sort
n = number of charcters in the products list
Time: O(nlog(n))

2. Build Trie
k = 3
m = number of characters in the longest product
Time: O(n)
Space: O(nkm)

3. Output Result
s = number of characters in searchword
Time: O(s)
Space: O(sk)


**/
class TrieNode {
  public:
    unordered_map<char, TrieNode*> children;
    vector<string> suggestions;
    
    TrieNode() {
      this->children = unordered_map<char, TrieNode*>();
      this->suggestions = {};
    }
  
    void addSuggestion(string& word) {
      int numSuggestions = this->suggestions.size();
      if (numSuggestions < 3) {
        this->suggestions.push_back(word);
      }
    }
};

class Trie {
  public:
    TrieNode* root;
    Trie() {
      this->root = new TrieNode();
    }
  
    void insert(string& word) {
      int len = word.length();
      TrieNode* crawler = this->root;
      for (char& ch: word) {
        if (crawler->children.find(ch) == crawler->children.end()) {
          TrieNode* trieNode = new TrieNode();
          crawler->children[ch] = trieNode;
        }
        
        crawler = crawler->children[ch];
        crawler->addSuggestion(word);
      }
      
    }
    
    vector<vector<string>> autocomplete(string& searchText) {
      TrieNode* crawler = this->root;
      vector<vector<string>> suggestedWords;
      for (char& ch: searchText) {
        vector<string> suggestions = {};
        if (!crawler) suggestedWords.push_back({});
        else {
          if (crawler->children.find(ch) != crawler->children.end()) {
            crawler = crawler->children[ch];
            suggestedWords.push_back(crawler->suggestions);
          } else {
            suggestedWords.push_back({});
            crawler = NULL;
          } 
        }
      }
      
      return suggestedWords;
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
      sort(products.begin(), products.end());
      Trie* trie = new Trie();
      for (string& product: products) {
        trie->insert(product);
      }
      
      vector<vector<string>> suggestedWords = trie->autocomplete(searchWord);
      
      return suggestedWords;
    }
};

/**

This solution was giving TLE
Because we are finding all the suggestions not first 3 suggested words
Also we are sorting suggested word's list at every step, means whenever user types a new character, the list we get will be sorted and then first 3 will be picked

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

**/