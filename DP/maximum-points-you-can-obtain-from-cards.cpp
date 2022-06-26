// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

// Currently WIP solution
class Solution {
private:
  int computeScoreRec(vector<int>& cardPoints, vector<int>& dp, int k, int start, int end) {
    if (k <= 0) return 0;
    if (start > end) return 0;
    if (dp[start] == -1) {
      dp[start] = cardPoints[start] + computeScoreRec(cardPoints, dp, k - 1, start + 1, end);
    }
    
    if (dp[end] == -1) {
      dp[end] = cardPoints[end] + computeScoreRec(cardPoints, dp, k - 1, start, end - 1);
    }
    return max(dp[start], dp[end]);
  }
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int start = 0;
        int end = cardPoints.size() - 1;
        vector<int> dp(end + 1, -1);
        int answer = computeScoreRec(cardPoints, dp, k, start, end);
      
        return answer;
    }
};


