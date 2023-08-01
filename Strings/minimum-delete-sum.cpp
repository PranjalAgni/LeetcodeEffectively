// https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/

// This solution uses LCS with some modifications to find 
// the subsequence with max ascii sum

// Approach to solve this:
// 1. Found the subsequence having max ascii sum (lets say allowed chars)
// 2. We just have to keep allowed chars and delete all others
// 3. Sum of deleted ascii vals will be our answer
// 4. Go recurse and code!

// Possible optimizations:
// 1. Instead of finding character array of largest ascii sum subsequence, 
// we can just find the max ascii sum of the characters

// 2. Instead of calculating the frequencyMap of strings we can just 
// sum their ascii value (let's say sum)

// 3. Now answer = (sum - maxAsciiSum * 2)


class Solution {
private:
    int getAsciiSum(vector<char>& chars) {
      int sum = 0;
      for (char& ch: chars) {
        int ascii = 97 + (ch - 'a');
        sum += ascii;
      }
      return sum;
    }
    vector<char> findLCS(map<pair<int, int>, vector<char>>& cache, string& s1, string& s2, int N, int M) {
      if (N < 0 || M < 0) return {};
      pair<int, int> key = make_pair(N, M);
      if (cache.find(key) != cache.end()) return cache[key];
      if (s1[N] == s2[M]) {
        vector<char> answer = findLCS(cache, s1, s2, N - 1, M - 1);
        answer.push_back(s1[N]);
        cache[key] = answer;
        return answer;
      } else {
        vector<char> choice1 = findLCS(cache, s1, s2, N - 1, M);
        vector<char> choice2 = findLCS(cache, s1, s2, N, M - 1);
        cache[key] = getAsciiSum(choice1) > getAsciiSum(choice2) ? choice1 : choice2;
        return cache[key];
      }
    }
  
    unordered_map<char, int> getLongestCommonSubsequence(string& s1, string& s2) {
      int N = s1.length();
      int M = s2.length();
      map<pair<int, int>, vector<char>> cache;
      vector<char> lcs =  findLCS(cache, s1, s2, N - 1, M - 1);
      unordered_map<char, int> lcsMap;
      for (char& ch: lcs) {
        lcsMap[ch] += 1;
      }
      cout << endl;
      return lcsMap;
    }
  
    vector<int> getFrequency(string& str) {
      int N = str.length();
      vector<int> frequencyTable(26, 0);
      for (int idx = 0; idx < N; idx++) {
        frequencyTable[str[idx] - 'a'] += 1;
      }
      
      return frequencyTable;
    }
public:
    int minimumDeleteSum(string s1, string s2) {
        unordered_map<char, int> lcsFrequency = getLongestCommonSubsequence(s1, s2);
        vector<int> freqMap1 = getFrequency(s1);
        vector<int> freqMap2 = getFrequency(s2);
        int answer = 0;
        
        for (int idx = 0; idx < 26; idx++) {
          int ascii = 97 + idx;
          int allowedCount = 2 * lcsFrequency[char(ascii)];
          int availableCount = freqMap1[idx] + freqMap2[idx];
          int countToRemove = abs(availableCount - allowedCount);
          answer += (ascii * countToRemove);
          
        }
      
        return answer;
    }
};