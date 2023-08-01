// https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/

// LCS but modified to find subsequence with max ascii sum
class Solution {
private:
    int findLargestAsciiSumSubsequence(map<pair<int, int>, int>& cache, string& s1, string& s2, int N, int M) {
      if (N < 0 || M < 0) return 0;
      pair<int, int> key = make_pair(N, M);
      if (cache.find(key) != cache.end()) return cache[key];
      if (s1[N] == s2[M]) {
        int answer = findLargestAsciiSumSubsequence(cache, s1, s2, N - 1, M - 1);
        answer += (97 + (s1[N] - 'a'));
        cache[key] = answer;
        return answer;
      } else {
        int choice1 = findLargestAsciiSumSubsequence(cache, s1, s2, N - 1, M);
        int choice2 = findLargestAsciiSumSubsequence(cache, s1, s2, N, M - 1);
        cache[key] = max(choice1, choice2);
        return cache[key];
      }
    }
  
    int getLargestAsciiSumSubsequence(string& s1, string& s2) {
      int N = s1.length();
      int M = s2.length();
      map<pair<int, int>, int> cache;
      return findLargestAsciiSumSubsequence(cache, s1, s2, N - 1, M - 1);
    }
public:
    int minimumDeleteSum(string s1, string s2) {
        int largestAsciiSum = getLargestAsciiSumSubsequence(s1, s2);
        int sum = 0;
        for (char& ch: s1) sum += ch;
        for (char& ch: s2) sum += ch;
        
        return sum - (2 * largestAsciiSum);
    }
};