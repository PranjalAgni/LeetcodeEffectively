// https://leetcode.com/problems/accounts-merge/
class Solution {
private:
    int find(vector<int>& parent, int idx) {
      if (idx == parent[idx]) return idx;
      else {
        parent[idx] = find(parent, parent[idx]);
        return parent[idx];
      }
    }
  
    void unionDS(vector<int>& parent, int x, int y) {
      parent[y] = parent[x];
    }
public:
    // Time: O(N*logN) | Space: O(N)
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int N = accounts.size();
        vector<int> parentList(N);
        for (int idx = 0; idx < N; idx++) parentList[idx] = idx;
      
        unordered_map<string, int> emailVsParentIdxMap;
        
        // put the email into its own parent buckets
        // each bucket belongs to a unique account
        for (int idx = 0; idx < N; idx++) {
          vector<string> account = accounts[idx];
          for (int pos = 1; pos < account.size(); pos++) {
            string email = account[pos];
            if (emailVsParentIdxMap.find(email) == emailVsParentIdxMap.end()) {
              emailVsParentIdxMap[email] = idx;
            } else {
              int parentIdx = emailVsParentIdxMap[email];
              unionDS(parentList, find(parentList, parentIdx), find(parentList, idx));
            }
          }
        }
      
        // compressing the paths
        for (int idx = 0; idx < N; idx++) {
          parentList[idx] = find(parentList, idx);
        }
        
        // build the email list for each unique bucket
        unordered_map<int, set<string>> parentIdxVsEmailList;
        for (int idx = 0; idx < N; idx++) {
          int parentIdx = parentList[idx];
          vector<string> account = accounts[idx];
          for (int pos = 1; pos < account.size(); pos++) {
            string email = account[pos];
            parentIdxVsEmailList[parentIdx].insert(email);
          }
        }
        
        // prepare the answer from the built maps
        vector<vector<string>> answer;
        for (const auto& [key, value]: parentIdxVsEmailList) {
          vector<string> currentAccount;
          vector<string> account = accounts[key];
          currentAccount.push_back(account[0]);
          copy(value.begin(), value.end(), back_inserter(currentAccount));
          answer.push_back(currentAccount);
        }
      
        return answer;
    }
};