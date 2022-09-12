// https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/

class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b) {
      if (a[0] == b[0]) {
        return a[1] > b[1];
      }
      
      return a[0] < b[0];
    }
  
    // Time: O(N * logN) | Space: O(1)
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int N = properties.size();
        sort(properties.begin(), properties.end(), comp);
        int answer = 0;
        int minAttack = INT_MIN;
        for (int idx = N - 1; idx >= 0; idx--) {
          if (properties[idx][1] < minAttack) answer += 1;
          minAttack = max(minAttack, properties[idx][1]);
        }
        
        return answer;
    }
};