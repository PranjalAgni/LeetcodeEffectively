/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* firstWrong, secondWrong, pre;
private:
    void inorder(TreeNode* root) {
      if (!root) return;
      inorder(root->left);
      if (firstWrong == nullptr && pre->val > root->val) {
        firstWrong = pre;
      } else if (firstWrong != nullptr && pre->val > root->val) {
        secondWrong = root;
      }
      
      pre = root;
      inorder(root->left);

    }
public:
    void recoverTree(TreeNode* root) {
        pre = new TreeNode(INT_MIN);
        inorder(root);
        swap(firstWrong->val, secondWrong->val);
    }
};