// https://leetcode.com/problems/minimum-speed-to-arrive-on-time/

// Very nice set of problems from BinarySearch

class Solution {
public:
    // Time: O(Klogk + N) | Space: O(1)
    // K = int(1e9)
    // N = Length of distances vector
    int minSpeedOnTime(vector<int>& dist, double hour) {
      int minSpeed = 1;
      int maxSpeed = int(1e9);
      int N = dist.size();
      double answer = -1;
      while (minSpeed <= maxSpeed) {
        int probableSpeed = (minSpeed + maxSpeed) / 2;
        double totalTime = 0;
        for (int idx = 0; idx < N - 1; idx++) {
          double timeTaken = (double)dist[idx] / probableSpeed;
          totalTime += ceil(timeTaken);
        }
        
        totalTime = totalTime + ((double)dist[N - 1] / probableSpeed);
        
        if (totalTime > hour) {
          minSpeed = probableSpeed + 1;
        } else {
          answer = probableSpeed;
          maxSpeed = probableSpeed - 1;
        }
      }
      
      return answer;
    }
};