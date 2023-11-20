// https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage

// Currently WIP problem
class Solution {
private:
    // Time: O(N) | Space: O(N)
    vector<int> getPrefixSum(vector<int>& travel, int& N) {
      vector<int> prefixSum(N);
      prefixSum[0] = 0;
      for (int idx = 1; idx < N; idx++) {
        prefixSum[idx] = prefixSum[idx - 1] + travel[idx - 1];
      }
      
      return prefixSum;
    }
    
    // Time: O(1) | Space: O(1)
    int computeExtraTime(vector<int>& prefixSum, int lastSeenAt, int currentIdx) {
      int distance = currentIdx - lastSeenAt;
      if (distance < 2) return 0;
      int timeToReachLastPosition = prefixSum[currentIdx - 1] - prefixSum[lastSeenAt];
      return timeToReachLastPosition;
    }
public:
    // Time: O(N*max(garbage[i].length)) | Space: O(N)
    // Storing last seen position of types of garbage and calculating distance if it's seen in future
    // Concurrently computing time taken to collect specific type of garbage & storing it separately
    // Adding back all the 3 time's computed
    // And that's it :)
    
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int N = garbage.size();
        vector<int> prefixSum = getPrefixSum(travel, N);
      
        vector<int> timeList(3, 0);
        vector<int> seenList(3, 0);
      
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
            timeList[0] += metalCollected;
            if (idx >= 1) {
              int extraTime = computeExtraTime(prefixSum, seenList[0], idx);
              timeList[0] += extraTime + travel[idx - 1];
            }
            seenList[0] = idx;
          }

          if (paperCollected > 0) {
            timeList[1] += paperCollected;
            if (idx >= 1) {
              int extraTime = computeExtraTime(prefixSum, seenList[1], idx);
              timeList[1] += extraTime + travel[idx - 1];
            }
            seenList[1] = idx;
          }

          if (garbageCollected > 0) {
            timeList[2] += garbageCollected;
            if (idx >= 1) {
              int extraTime = computeExtraTime(prefixSum, seenList[2], idx);
              timeList[2] += extraTime + travel[idx - 1];
            }
            seenList[2] = idx;
          }
        }
      
        return timeList[0] + timeList[1] + timeList[2];
    }
};