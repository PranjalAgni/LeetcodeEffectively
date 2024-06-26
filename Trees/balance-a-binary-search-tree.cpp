// https://leetcode.com/problems/balance-a-binary-search-tree/submissions/

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
 // Time: O(N) | Space: O(N)
class Solution {
private:
    void inorderTraversal(TreeNode* root, vector<int>& inorder) {
      if (!root) return;
      inorderTraversal(root->left, inorder);
      inorder.push_back(root->val);
      inorderTraversal(root->right, inorder);
    }
  
    TreeNode* balanceBSTHelper(vector<int>& inorder, int low, int high) {
      if (low > high) return nullptr;
      int mid = low + (high - low) / 2;
      int currentValue = inorder[mid];
      TreeNode* node = new TreeNode(currentValue);
      node->left = balanceBSTHelper(inorder, low, mid - 1);
      node->right = balanceBSTHelper(inorder, mid + 1, high);
      return node;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorder;
        inorderTraversal(root, inorder);
        int low = 0;
        int high = inorder.size() - 1;
        return balanceBSTHelper(inorder, low, high);
    }
};