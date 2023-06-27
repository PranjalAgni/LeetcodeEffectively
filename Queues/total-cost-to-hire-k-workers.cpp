// https://leetcode.com/problems/total-cost-to-hire-k-workers/

// Simple approach uses priority queue (min heap) to get the minimun cost
// for picking the candidate
class Solution {
public:
    // Time: O(N*logN) | Space: O(N)
    // N = number of elements in costs
    long long totalCost(vector<int>& costs, int k, int candidates) {
      int N = costs.size();
      
      priority_queue<int, vector<int>, greater<int>> firstHeap;
      priority_queue<int, vector<int>, greater<int>> secondHeap;
      
      int start = 0;
      int end = N - 1;
      long long answer = 0;
      while (k-- > 0) {
        while (firstHeap.size() < candidates && start < N) {
          firstHeap.push(costs[start]);
          start += 1;
        }
        
        while (secondHeap.size() < candidates && end >= start) {
          secondHeap.push(costs[end]);
          end -= 1;
        }
        
        int cost1 = firstHeap.size() > 0 ? firstHeap.top() : INT_MAX;
        int cost2 = secondHeap.size() > 0 ? secondHeap.top() : INT_MAX;
        
        if (cost1 <= cost2) {
          answer += cost1;
          firstHeap.pop();
        } else {
          answer += cost2;
          secondHeap.pop();
        }
      }
      
      return answer;
      
    }
};