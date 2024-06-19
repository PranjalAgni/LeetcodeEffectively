// https://leetcode.com/problems/merge-intervals/

// Time: O(N*logN) | Space: O(N)
// N = length of intervals
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int N = intervals.size();
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> answer;
        answer.push_back(intervals[0]);
        int pos = 0;
        for (int idx = 1; idx < N; idx++) {     
          if (answer[pos][1] >= intervals[idx][0]) {
            answer[pos][1] = max(intervals[idx][1], answer[pos][1]);
          } else {
            answer.push_back(intervals[idx]);
            pos += 1;
          }
        }
      
        return answer;
    }
};