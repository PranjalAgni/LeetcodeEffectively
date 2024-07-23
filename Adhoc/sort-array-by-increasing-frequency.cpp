// https://leetcode.com/problems/sort-array-by-increasing-frequency/

// TC: O(N*logN) | Space: O(N)
class Solution {
public:
    static bool comparatorFn(pair<int, int>& a, pair<int, int>& b) {
      if (a.first == b.first) {
        return a.second > b.second;
      }
      
      return a.first < b.first;
    }
  
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freqMap;
        for (int& num: nums) {
          freqMap[num] += 1;
        }
      
        vector<pair<int, int>> numsWithFrequency;
        for (const auto& it: freqMap) {
          numsWithFrequency.push_back(make_pair(it.second, it.first));
        }
      
        sort(numsWithFrequency.begin(), numsWithFrequency.end(), comparatorFn);
        vector<int> answer;
        for (pair<int, int>& p: numsWithFrequency) {
          int times = p.first;
          while(times-- > 0) {
            answer.push_back(p.second);
          }
        }
      
        return answer;
    }
};