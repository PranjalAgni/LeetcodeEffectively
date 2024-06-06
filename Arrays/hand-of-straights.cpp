// https://leetcode.com/problems/hand-of-straights/

// Time: O(NlogN) | Space: O(N)
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int N = hand.size();
        if (N % groupSize != 0) return false;
        if (N == 1) return true;
        
        int totalGroups = N / groupSize;
        int groupFormed = 0;
      
        sort(hand.begin(), hand.end());
        unordered_map<int, int> freqMap;
        for (int& elt: hand) {
          freqMap[elt] += 1;
        }
      
        for (int idx = 0; idx < N; idx++) {
          int start = hand[idx];
          if (freqMap[start] <= 0) continue;
          freqMap[start] -= 1;
          int group = groupSize - 1;
          while (group-- > 0) {
            if (freqMap[start + 1] == 0) return false;
            freqMap[start + 1] -= 1;
            start += 1;
          }
          
          groupFormed += 1;
          if (groupFormed == totalGroups) break;
        }
       
        return true;
        
    }
};
