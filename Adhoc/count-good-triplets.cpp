// https://leetcode.com/problems/count-good-triplets/?envType=daily-question&envId=2025-04-14

// Time: O(N^3) | Space: O(1)
class Solution {
  public:
      int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
          int N = arr.size();
          int answer = 0;
  
          for (int idx = 0; idx < N; idx++) {
              for (int jdx = idx + 1; jdx < N; jdx++) {
                  for (int kdx = jdx + 1; kdx < N; kdx++) {
                      int x = abs(arr[idx] - arr[jdx]);
                      int y = abs(arr[jdx] - arr[kdx]);
                      int z = abs(arr[idx] - arr[kdx]);
  
                      if (x <= a && y <= b && z <= c) answer += 1;
                  }
              }
          }
  
          return answer;
      }
  };