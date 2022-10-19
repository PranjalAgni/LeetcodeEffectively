// https://leetcode.com/problems/top-k-frequent-words/

class Solution {
private:
    // Time: O(N) | Space: O(N)
    unordered_map<string, int> computeFrequencyMap(vector<string>& words) {
      unordered_map<string, int> frequencyMap;
      for (string& word: words) {
        frequencyMap[word] += 1;
      }
      
      return frequencyMap;
    }
  
    // Time: O(N) | Space: O(K)
    vector<pair<string, int>> getFrequencyWordList(unordered_map<string, int> frequencyMap) {
      vector<pair<string, int>> frequencyWordList;
      unordered_map<string, int>::iterator it;
      for (it = frequencyMap.begin(); it != frequencyMap.end(); it++) {
        pair<string, int> p = make_pair(it->first, it->second);
        frequencyWordList.push_back(p);
      }
      return frequencyWordList;
    }
    
    static bool compratorFn(pair<string, int>& a, pair<string, int>& b) {
      if (a.second == b.second) {
        return a.first < b.first;
      }
      return a.second > b.second;
    }
  
public:
    // Time: O(K*log(K)) | Space: O(N)
    // K = total number of unique words
    // N = total number of words
    vector<string> topKFrequent(vector<string>& words, int k) {
      // get the frequency map
      unordered_map<string, int> frequencyMap = computeFrequencyMap(words);
      // create top k list
      vector<pair<string, int>> frequencyWordList = getFrequencyWordList(frequencyMap);
      // sort the list with custom comparator fn
      sort(frequencyWordList.begin(), frequencyWordList.end(), compratorFn);
      
      // prepare the answer
      vector<string> answer;
      for (int idx = 0; idx < k; idx++) {
        answer.push_back(frequencyWordList[idx].first);
      }
      return answer;
    }
};