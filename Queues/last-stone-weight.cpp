// https://leetcode.com/problems/last-stone-weight/

class Solution {
public:
    // Time: O(NlogN) | Space: O(N)
    // N = size of stones array
    // Using priority queues acting as a  max heap
    int lastStoneWeight(vector<int>& stones) {
      priority_queue<int> pq(stones.begin(), stones.end());
      
      while (pq.size() > 1) {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        if (first != second) {
          int diff = first - second;
          pq.push(diff);
        }
      }
      
      return pq.size() ? pq.top() : 0;
    }
};