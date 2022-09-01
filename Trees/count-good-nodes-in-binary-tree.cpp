// https://leetcode.com/problems/count-good-nodes-in-binary-tree/

class Solution {
private:
   // Time: O(N) | Space: O(H)
   // N = number of nodes in tree
   // H = height of the tree
   int findGoodNodes(TreeNode* root, int maxValue) {
     if (!root) return 0;
     int res = root->val >= maxValue ? 1 : 0;
     res += findGoodNodes(root->left, max(maxValue, root->val));
     res += findGoodNodes(root->right, max(maxValue, root->val));
     return res;
   }
public:
    int goodNodes(TreeNode* root) {
        return findGoodNodes(root, INT_MIN);
    }
};