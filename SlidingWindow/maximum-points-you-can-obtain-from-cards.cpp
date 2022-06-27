// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

// Time: O(N) | Space: O(N)
class Solution {
private:
  int computeSum(vector<int>& cardPoints) {
    int sum = 0;
    for (int elt: cardPoints) sum += elt;
    return sum;
  }
  
  int getKMinSubarraySum(vector<int>& cardPoints, int K) {
    int N = cardPoints.size();
    int start = 0;
    int end = 0;
    int minSum = INT_MAX;
    int currSum = 0;
    int windowSize = N - K;
    while (end < N) {
      currSum += cardPoints[end];
      if (end - start + 1 > windowSize) {
        currSum -= cardPoints[start];
        start += 1;
      }
      
      if (end - start + 1 == windowSize) {
        minSum = min(minSum, currSum);
      }
      end += 1;
    }
    
    return minSum;
  }
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = computeSum(cardPoints);  
        int minSum = getKMinSubarraySum(cardPoints, k);
        return sum - minSum;
    }
};