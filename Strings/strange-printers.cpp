// https://leetcode.com/problems/strange-printer/

class Solution {
public:
    int strangePrinter(string s) {
        int N = s.length();
        map<char, vector<int>> hashMap;
        for (int idx = 0; idx < N; idx++) {
          vector<int> positions = hashMap[s[idx]];
          if (positions.size() == 0) {
            positions.insert(positions.end(), {INT_MAX, INT_MIN});
          }
          
          positions[0] = min(idx, positions[0]);
          positions[1] = max(idx, positions[1]);
          hashMap[s[idx]] = positions;
        }
      
        int answer = 0;
        for (auto& i : hashMap) {
          vector<int> positions = i.second;
          answer += 1;
          // cout << i.first << " " << positions[0] << ":" << positions[1] << endl;
        }
       
      
        return answer;
    }
};