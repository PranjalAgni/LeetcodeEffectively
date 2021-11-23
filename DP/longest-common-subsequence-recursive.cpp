#include <vector>
using namespace std;

// Recursive solution
// Time: O(N*M) | Space: O(N + M)
vector<char> computeLongestCommonSequence(
    string& str1, string& str2, int N, int M,
    map<pair<int, int>, vector<char>>& cache) {
    if (N < 0 || M < 0) return {};
    pair<int, int> key = make_pair(N, M);
    if (cache.find(key) != cache.end()) return cache[key];

    char chA = str1[N];
    char chB = str2[M];

    if (chA == chB) {
        vector<char> answer =
            computeLongestCommonSequence(str1, str2, N - 1, M - 1, cache);
        answer.push_back(chA);
        cache[key] = answer;
        return answer;
    } else {
        vector<char> answer1 =
            computeLongestCommonSequence(str1, str2, N - 1, M, cache);
        vector<char> answer2 =
            computeLongestCommonSequence(str1, str2, N, M - 1, cache);
        cache[key] = (answer1.size() > answer2.size()) ? answer1 : answer2;
        return cache[key];
    }
}

vector<char> longestCommonSubsequence(string& str1, string& str2) {
    int N = str1.length() - 1;
    int M = str2.length() - 1;
    map<pair<int, int>, vector<char>> cache;
    return computeLongestCommonSequence(str1, str2, N, M, cache);
}
