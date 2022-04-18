// https://leetcode.com/problems/increasing-order-search-tree/

class Solution {
private:
  // Time: O(N) | Space: O(N)
  void inorder(TreeNode* root, vector<int>& inorderList) {
    if (!root) return;
    inorder(root->left, inorderList);
    inorderList.push_back(root->val);
    inorder(root->right, inorderList);
  }
public:
    // Time: O(N) | Space: O(N)
    TreeNode* increasingBST(TreeNode* root) {
      if (!root) return NULL;
      vector<int> inorderList;
      inorder(root, inorderList);
      TreeNode* newRoot = new TreeNode(-1);
      TreeNode* current = newRoot;
      
      for (int val: inorderList) {
        current->right = new TreeNode(val);
        current = current->right;
      }
      
      return newRoot->right;
    }
};