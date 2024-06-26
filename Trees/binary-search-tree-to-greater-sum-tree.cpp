// https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/submissions/

// Time: O(N) | Space: O(1)
class Solution {
private:
    void bstToGstHelper(TreeNode* root, int& offset) {
      if (!root) return;
      bstToGstHelper(root->right, offset);
      root->val += offset;
      offset = root->val;
      bstToGstHelper(root->left, offset);
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        bstToGstHelper(root, sum);
        return root;
    }
};