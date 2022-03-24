// https://leetcode.com/problems/boats-to-save-people/
class Solution {
public:
    void printVector(vector<int>& vec) {
      for (int elt: vec) cout << elt << " ";
      cout << endl;
      return;
    }
  
    void numRescueBoatsRec(vector<int>& people, int idx, int& N, int& limit, set<vector<int>>& hashSet, vector<int> current, int sum) {
      if (idx >= N) return;
      
      numRescueBoatsRec(people, idx + 1, N, limit, hashSet, current, sum);
      if (current.size() < 2) {
        sum += people[idx];
        current.push_back(people[idx]);
      }
      if (sum <= limit) {
        printVector(current);
        hashSet.insert(current);
      }
      
      numRescueBoatsRec(people, idx + 1, N, limit, hashSet, current, sum);
    }
  
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int N = people.size();
        set<vector<int>> hashSet;
        numRescueBoatsRec(people, 0, N, limit, hashSet, {}, 0);
        return hashSet.size();
    }
};