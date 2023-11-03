// https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/

//Before we calculated the sum for every sub tree.

// Here we do a postorder traversal, we will calculate the sum of nodes in left sub tree and cnt of nodes in left subtree , as well as for right subtree and use this to root.

class Solution {
private:
    int ans = 0;
    pair<int, int> findAverage(TreeNode* root) {
      if (root == NULL) return {0, 0};
      
      auto left = findAverage(root->left);
      int leftSum = left.first;
      int leftCnt = left.second;
      
      auto right = findAverage(root->right);
      int rightSum = right.first;
      int rightCnt = right.second;
      
      int sum = root->val + leftSum + rightSum;
      int cnt = leftCnt + rightCnt + 1;
      
      if (root->val == sum / cnt) ans += 1;
      return {sum, cnt};
    }
public:
    // Time: O(N) | Space: O(N)
    int averageOfSubtree(TreeNode* root) {
        findAverage(root);
        return ans;
    }
};