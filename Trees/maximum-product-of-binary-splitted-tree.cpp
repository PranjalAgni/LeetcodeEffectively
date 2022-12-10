// https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/
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
    long long computeSum(TreeNode* root) {
      if (root == NULL) return 0;
      long long sum = computeSum(root->left) + computeSum(root->right) + root->val;
      return sum;
    }
  
    int computeMaxProduct(TreeNode* root, long long& total, long long& answer) {
      if (root == NULL) return 0;
      int sum = computeMaxProduct(root->left, total, answer) + computeMaxProduct(root->right, total, answer) + root->val;
      
       answer = max(answer, sum * (total - sum));
       return sum; 
    }
public:
    // Time: O(N) | Space: O(1)
    // not considering space taken by call stack for recursive functions
    int maxProduct(TreeNode* root) {
        long long total = computeSum(root);
        long long answer = INT_MIN;
        computeMaxProduct(root, total, answer);
        return answer % int(1e9 + 7);
    }
};