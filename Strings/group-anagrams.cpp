#include <bits/stdc++.h>

using namespace std;

// Time: O(W * N * log(N)) | Space: O(N*N)
// W = Number of words
// N = Length of longest word
vector<vector<string>> groupAnagrams(vector<string> words) {
    vector<vector<string>> anagramsAnswer;
    int N = words.size();
    unordered_map<string, vector<string>> hashMap;

    for (string word : words) {
        string sortedWord = word;
        sort(sortedWord.begin(), sortedWord.end());
        vector<string> currentGroup = hashMap[sortedWord];
        currentGroup.push_back(word);
        hashMap[sortedWord] = currentGroup;
    }

    for (const auto [key, value] : hashMap) {
        anagramsAnswer.push_back(value);
    }

    return anagramsAnswer;
}
