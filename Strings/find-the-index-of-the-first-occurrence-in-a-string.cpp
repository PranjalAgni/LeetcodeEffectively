// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/

// This is not a optimized solution, will implement a linear solution
// which uses 2 pointer approach
class Solution {
public:
    // Time: O(N * M) | Space: O(M)
    int strStr(string haystack, string needle) {
        int N = haystack.length();
        int M = needle.length();
      
        if (M > N) return -1;
      
        for (int idx = 0; idx <= N - M; idx++) {
          string current = haystack.substr(idx, M);
          if (current == needle) return idx;
        }
      
        return -1;
    }
};