// https://leetcode.com/problems/find-mode-in-binary-search-tree/

// Follow up: Solve it without using extra space

class Solution {
private:
    void collectElements(TreeNode* root, unordered_map<int, int>& hashMap, int& maxFreq) {
      if (root == NULL) return;
      hashMap[root->val] += 1;
      maxFreq = max(maxFreq, hashMap[root->val]);
      collectElements(root->left, hashMap, maxFreq);
      collectElements(root->right, hashMap, maxFreq);
    }
public:
    // Time: O(N) | Space: O(N)
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> hashMap;
        int maxFrequency = 0;
        collectElements(root, hashMap, maxFrequency);
      
        vector<int> answer;
        for (const auto& itr: hashMap) {
            if (itr.second == maxFrequency) {
              answer.push_back(itr.first);
            }
        }
      
        return answer;
    }
};