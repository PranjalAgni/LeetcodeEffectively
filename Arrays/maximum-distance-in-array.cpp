// https://leetcode.com/problems/maximum-distance-in-arrays/

// TC: O(N) | Space: O(1)
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int M = arrays.size();
        int minV = arrays[0][0];
        int maxV = arrays[0][arrays[0].size() - 1];
        
        int result = INT_MIN;
        for (int idx = 1; idx < M; idx++) {
          result = max(result, abs(arrays[idx][arrays[idx].size() - 1] - minV));
          result = max(result, abs(arrays[idx][0] - maxV));
          minV = min(minV, arrays[idx][0]);
          maxV = max(maxV, arrays[idx][arrays[idx].size() - 1]);
        }
      
        return result;
    }
};

