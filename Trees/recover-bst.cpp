// https://leetcode.com/problems/recover-binary-search-tree/

class Solution {
public:
    TreeNode* firstWrong = NULL;
    TreeNode* secondWrong = NULL;
    TreeNode* pre = new TreeNode(INT_MIN);
private:
    void inorder(TreeNode* root) {
      if (!root) return;
      inorder(root->left);
      if (firstWrong == nullptr && pre->val > root->val) {
        firstWrong = pre;
      }
      if (firstWrong != nullptr && pre->val > root->val) {
        secondWrong = root;
      }
      
      pre = root;
      inorder(root->right);
    }
public:
    // Time: O(N) | Space: O(1)
    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(firstWrong->val, secondWrong->val);
    }
};