// https://leetcode.com/problems/find-all-anagrams-in-a-string/

class Solution {
private:
    unordered_map<char, int> prepareStringMap(string& str) {
      unordered_map<char, int> freqMap;
      for (char& ch: str) {
        freqMap[ch] += 1;
      }
      
      return freqMap;
    }
    
    bool compareMaps(unordered_map<char, int> hashMap, unordered_map<char, int>& patternMap) {
      for (auto& [key, value]: patternMap) {
        hashMap[key] -= value;
      }
      
      for (auto& [key, value]: hashMap) {
        if (value != 0) return false;
      }
      
      return true;
    }
public:
    // Time: O(N) | Space: O(1)
    // Sliding window approach
    vector<int> findAnagrams(string s, string p) {
        int N = s.length(); 
        int M = p.length();
        if (M > N) return {};
        vector<int> answer;
        unordered_map<char, int> patternMap = prepareStringMap(p);
        unordered_map<char, int> hashMap;
        int left = 0;
        int right = 0;
        while (right < N) {
          hashMap[s[right]] += 1;
          if (right - left + 1 == M) {
            bool isAnagram = compareMaps(hashMap, patternMap);
            if (isAnagram) answer.push_back(left);
            hashMap[s[left]] -= 1;
            left += 1;
          }
          right += 1;
        }
      
        return answer;
    }
};