// https://leetcode.com/problems/find-bottom-left-tree-value/

// Idea: We can find the most left element in the tree, by traversing in level order traversal manner but the catch is we need to travel right to left in the tree, the last element which we reach will be the most left node in that given tree.
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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> queue;
        queue.push(root);
        while(!queue.empty()) {
          root = queue.front();
          queue.pop();
          if (root->right) queue.push(root->right);
          if (root->left) queue.push(root->left);
        }
      
        return root->val;
    }
};