// https://leetcode.com/problems/eliminate-maximum-number-of-monsters/

// Nice sorting problem
class Solution {
public:
    // Time: O(N*log(N)) | Space: O(N)
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int N = dist.size();
        vector<int> arrival(N);
        for (int idx = 0; idx < N; idx++) {
          arrival[idx] = (dist[idx] - 1) / speed[idx];
        }
      
        sort(arrival.begin(), arrival.end());
        
        for (int idx = 0; idx < N; idx++) {
          if (idx > arrival[idx]) return idx;
        }
      
        return arrival.size();
    }
};