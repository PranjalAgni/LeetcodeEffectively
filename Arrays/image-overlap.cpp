// https://leetcode.com/problems/image-overlap/

class Solution {
public:
    // Time: O(N * N) | Space: O(N)
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int N = img1.size();
        vector<pair<int, int>> vpImg1;
        vector<pair<int, int>> vpImg2;
      
        for (int row = 0; row < N; row++) {
          for (int col = 0; col < N; col++) {
            if (img1[row][col] == 1) {
              vpImg1.push_back({row, col});
            }
            
            if (img2[row][col] == 1) {
              vpImg2.push_back({row, col});
            }
          }
        }
      
        int answer = 0;
        map<pair<int,int>, int> mp;
        for (pair<int, int>& pImg1: vpImg1) {
          for (pair<int, int>& pImg2: vpImg2) {
            int a = pImg1.first - pImg2.first;
            int b = pImg1.second - pImg2.second;
            mp[{a,b}] += 1;
            answer = max(answer, mp[{a,b}]);
          }
        }
      
        return answer;
    }
};