// https://leetcode.com/problems/binary-tree-tilt

class Solution {
private:
   int tiltBinaryTree(TreeNode* root, int& sum) {
     if (!root) return 0;      
     int leftSum = tiltBinaryTree(root->left, sum);
     int rightSum = tiltBinaryTree(root->right, sum);
     sum += abs(leftSum - rightSum);
     return leftSum + root->val + rightSum;
   }
  
public:
    // Time: O(N) | Space: O(1)
    int findTilt(TreeNode* root) {
      int sum = 0;
      tiltBinaryTree(root, sum);
      return sum;
    }
};