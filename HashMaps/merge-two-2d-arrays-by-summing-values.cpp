// https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/

// Time: O(N + M) | Space: O(N + M)
// N = nums1.size()
// M = nums2.size()
class Solution {
  public:
      vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
          int N = nums1.size();
          int M = nums2.size();
  
          int idx = 0;
          int jdx = 0;
  
          map<int, int> hashMap;
          while (idx < N || jdx < M) {
              int id = 0;
              int val = 0;
              if ((idx < N) && (jdx < M)) {
                  int id1 = nums1[idx][0];
                  int id2 = nums2[jdx][0];
  
                  if (id1 == id2) {
                      id = id1;
                      val = nums1[idx][1] + nums2[jdx][1];
                      idx += 1;
                      jdx += 1;
                  } else if (id1 < id2) {
                      id = id1;
                      val = nums1[idx][1];
                      idx += 1;
                  } else {
                      id = id2;
                      val = nums2[jdx][1];
                      jdx += 1;
                  }
              } else if (idx < N) {
                  id = nums1[idx][0];
                  val = nums1[idx][1];
                  idx += 1;
              } else {
                  id = nums2[jdx][0];
                  val = nums2[jdx][1];
                  jdx += 1;
              }
  
              hashMap[id] += val;
          }
  
          vector<vector<int>> answer;
          for (auto const& it: hashMap) {
              answer.push_back({it.first, it.second});
          }
  
          return answer;
      }
  };