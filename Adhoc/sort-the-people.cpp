// https://leetcode.com/problems/sort-the-people/

// Time: O(N) | Space: O(N)
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, int>> heightsWithIndex;
        int N = heights.size();
        for (int idx = 0; idx < N; idx++) {
          heightsWithIndex.push_back(make_pair(heights[idx], idx));
        }
      
        sort(heightsWithIndex.begin(), heightsWithIndex.end());
        vector<string> answer;
      
        for (int idx = N - 1; idx >= 0; idx--) {
          int h = heightsWithIndex[idx].second;
          answer.push_back(names[h]);
        }
      
        return answer;
    }
};