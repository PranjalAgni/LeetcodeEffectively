// https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage

// Currently WIP problem
class Solution {
private:
    vector<int> getPrefixSum(vector<int>& travel, int& N) {
      vector<int> prefixSum(N);
      prefixSum[0] = 0;
      for (int idx = 1; idx < N; idx++) {
        prefixSum[idx] = prefixSum[idx - 1] + travel[idx - 1];
      }
      
      return prefixSum;
    }  
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int N = garbage.size();
        vector<int> prefixSum = getPrefixSum(travel, N);
        int lastIndexMetalScene = 0;
        int lastIndexPaperScene = 0;
        int lastIndexGarbageScene = 0;
      
        int timeMetal = 0;
        int timePaper = 0;
        int timeGarbage = 0;
        
        for (int idx = 0; idx < N; idx++) {
          int metalCollected = 0;
          int paperCollected = 0;
          int garbageCollected = 0;
          string assortment = garbage[idx];
          for (char& ch: assortment) {
            if (ch == 'M') {
              metalCollected += 1;
            } else if (ch == 'P') {
              paperCollected += 1;
            } else {
              garbageCollected += 1;
            }
          }
          
          if (metalCollected > 0) {
            timeMetal += metalCollected;
            if (idx >= 1) {
              int diff = idx - lastIndexMetalScene;
              int extraTime = 0;
              if (diff > 1) {
                extraTime = prefixSum[idx - 1] - prefixSum[lastIndexMetalScene];
              }
              
              timeMetal += extraTime + travel[idx - 1];
              
            }
            lastIndexMetalScene = idx;
          }

          if (paperCollected > 0) {
            timePaper += paperCollected;
            if (idx >= 1) {
              int diff = idx - lastIndexPaperScene;
              int extraTime = 0;
              if (diff > 1) {
                extraTime = prefixSum[idx - 1] - prefixSum[lastIndexPaperScene];
              }
              
              timePaper += extraTime + travel[idx - 1];
              
            }
            lastIndexPaperScene = idx;
          }

          if (garbageCollected > 0) {
            timeGarbage += garbageCollected;
            if (idx >= 1) {
              int diff = idx - lastIndexGarbageScene;
              int extraTime = 0;
              if (diff > 1) {
                extraTime = prefixSum[idx - 1] - prefixSum[lastIndexPaperScene];
              }
              
              cout << "Extra time taken: " << extraTime;
              
              timeGarbage += extraTime + travel[idx - 1];
              
            }
            lastIndexGarbageScene = idx;
          }
        }
      
        return timeMetal + timePaper + timeGarbage;
    }
};