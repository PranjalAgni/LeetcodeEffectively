// https://leetcode.com/problems/find-the-winner-of-an-array-game/

// Direct problem, just simulating the game and using List for optimization
class Solution {
public:
    // Time: O(N) | Space: O(N)
    int getWinner(vector<int>& arr, int k) {
      int N = arr.size();
      list<int> arrList(arr.begin(), arr.end());
      int wonCount = 0;
      int prevWon = INT_MIN;
      int won;
      
      while (wonCount != k && N-- > 0) {
        int first = arrList.front();
        arrList.pop_front();
        int second = arrList.front();
        arrList.pop_front();
        
        won = max(first, second);
        int lost = min(first, second);
        
        arrList.push_front(won);
        arrList.push_back(lost);
        
        if (prevWon == won) wonCount += 1;
        else wonCount = 1;
        
        prevWon = won;
      }
      
      return won;
    }
};