// https://leetcode.com/problems/furthest-building-you-can-reach/

class Solution {
private:
  void findFurtherestWeCanReachWithRecursion(vector<int>& heights, priority_queue<int>& brickUsed,int bricks, int ladders, int position, int& answer) { 
    int N = heights.size(); 
    answer = max(answer, position);
    if (position >= N - 1) return;
    int a = heights[position];
    int b = heights[position + 1];
    if (a < b) {
      int bricksReqd = heights[position + 1] - heights[position];
      if (bricksReqd <= bricks) {
        brickUsed.push(bricksReqd);
        findFurtherestWeCanReachWithRecursion(heights, brickUsed, bricks - bricksReqd, ladders, position + 1, answer);
      } else if (ladders > 0) {
        if (!brickUsed.empty() && brickUsed.top() >= bricksReqd) {
          bricks = bricks + brickUsed.top() - bricksReqd;
          brickUsed.pop();
          brickUsed.push(bricksReqd);
        }
        findFurtherestWeCanReachWithRecursion(heights, brickUsed, bricks, ladders - 1, position + 1, answer);
      }
    } else {
      findFurtherestWeCanReachWithRecursion(heights, brickUsed, bricks, ladders, position + 1, answer);
    }
  }
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int N = heights.size();
        priority_queue<int> brickUsed;
        int reachedIndex = 0;
        findFurtherestWeCanReachWithRecursion(heights, brickUsed, bricks, ladders, 0, reachedIndex);
      
        return reachedIndex;
    }
};