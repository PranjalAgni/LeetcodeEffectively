class Solution {
private:
  void computeRangeSum(TreeNode* root, int& low, int& high, int& sum) {
    if (!root) return;
    if (root->val >= low && root->val <= high) sum += root->val;
    if (root->val > low) computeRangeSum(root->left, low, high, sum);
    if (root->val < high) computeRangeSum(root->right, low, high, sum);
  }
public: 
    // Time: O(N) | Space: O(H)
    // N = numbe of nodes
    // H = height of tree
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        computeRangeSum(root, low, high, sum);
        return sum;
    }
};