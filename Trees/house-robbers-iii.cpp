// https://leetcode.com/problems/house-robber-iii/

// Time: O(N) | Space: O(N)
class Solution {
public:
    unordered_map<TreeNode*, int> hashMap;
    int robRec(TreeNode* root) {
      if (!root) return 0;
      if (hashMap[root]) return hashMap[root];
      int leftMax = 0, rightMax = 0;
      if (root->left) {
        leftMax = robRec(root->left->left) + robRec(root->left->right);
      }
      
      if (root->right) {
        rightMax = robRec(root->right->left) + robRec(root->right->right);
      }
      
      hashMap[root] = max(root->val + leftMax + rightMax, robRec(root->left) + robRec(root->right));
      
      return hashMap[root];
    }
  
    int rob(TreeNode* root) {
      return robRec(root);    
    }
};