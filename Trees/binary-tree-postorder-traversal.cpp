// https://leetcode.com/problems/binary-tree-postorder-traversal/

// Time: O(N) | Space: O(N)
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
private:
    void traverse(TreeNode* root, vector<int>& answer) {
      if (!root) return;
      traverse(root->left, answer);
      traverse(root->right, answer);
      answer.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> answer;
        traverse(root, answer);
        return answer;
    }
};