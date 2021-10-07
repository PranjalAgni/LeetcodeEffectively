#include <unordered_map>
using namespace std;

class TrieNode {
   public:
    unordered_map<char, TrieNode*> children;
};

class SuffixTrie {
   public:
    TrieNode* root;
    char endSymbol;

    SuffixTrie(string str) {
        this->root = new TrieNode();
        this->endSymbol = '*';
        this->populateSuffixTrieFrom(str);
    }

    void insertSubstringStartingAt(string str, int pos) {
        int len = str.length();
        TrieNode* crawlNode = this->root;
        for (int idx = pos; idx < len; idx++) {
            if (crawlNode->children.find(str[idx]) ==
                crawlNode->children.end()) {
                TrieNode* trieNode = new TrieNode();
                crawlNode->children[str[idx]] = trieNode;
            }
            crawlNode = crawlNode->children[str[idx]];
        }

        crawlNode->children[this->endSymbol] = NULL;
    }

    // Time: O(N * N) | Space: O(N * N)
    // N = length of the string
    void populateSuffixTrieFrom(string str) {
        int len = str.length();
        for (int idx = 0; idx < len; idx++) {
            this->insertSubstringStartingAt(str, idx);
        }
    }

    // Time: O(N)  | Space: O(1)
    // N = length of the string
    bool contains(string str) {
        TrieNode* crawlNode = this->root;
        for (char ch : str) {
            if (crawlNode->children.find(ch) == crawlNode->children.end())
                return false;
            crawlNode = crawlNode->children[ch];
        }
        return crawlNode->children.find(this->endSymbol) !=
               crawlNode->children.end();
    }
};
