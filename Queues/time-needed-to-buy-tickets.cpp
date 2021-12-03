// https://leetcode.com/contest/weekly-contest-267/problems/time-needed-to-buy-tickets/

class Solution {
public:
    // Time: O(N) | Space: O(N)
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int,int>> q;
        
        int N = tickets.size();
        for (int idx = 0; idx < N; idx++) q.push({tickets[idx], idx});
      
        int time = 0;
        while (true) {
          pair<int, int> current = q.front();
          q.pop();
          time += 1;
          
          int ticketsLeft = current.first - 1;
          if (k == current.second && ticketsLeft == 0) break;
          if (ticketsLeft != 0) q.push({ticketsLeft, current.second});
          
        }
      
        return time;
    }
};