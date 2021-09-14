#include <vector>
using namespace std;

// Time: O(N * L) | Space: O(c)
// N = Number of words
// L = Length of longest word
// c = number of unique characters acorss all words
vector<char> minimumCharactersForWords(vector<string> words) {
    unordered_map<char, int> hashMap;
    vector<char> charList;
    for (string str : words) {
        unordered_map<char, int> currentFreq;
        for (char ch : str) {
            currentFreq[ch] += 1;
            if (currentFreq[ch] > hashMap[ch]) {
                charList.push_back(ch);
                hashMap[ch] = currentFreq[ch];
            }
        }
    }
    return charList;
}