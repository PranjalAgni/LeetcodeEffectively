// https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int N = properties.size();
        sort(properties.begin(), properties.end());
        int answer = 0;
        int minAttack = INT_MAX;
        // for (vector<int>& p: properties) {
        //   cout << p[0] << " " << p[1] << endl;
        // }
        for (int idx = 1; idx < N; idx++) {
          vector<int> previous = properties[idx - 1];
          vector<int> current = properties[idx];
          minAttack = min(minAttack, previous[1]);
          if (previous[0] < current[0] && minAttack < current[1]) {
            answer += 1;
          }
        }
        
        return answer;
    }
};