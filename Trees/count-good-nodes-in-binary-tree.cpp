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
   void findGoodNodes(TreeNode* root, int& ans) {
     if (!root) return;
     
   }
public:
    int goodNodes(TreeNode* root) {
        int ans = 0;
        findGoodNodes(root, ans);
        return ans;
    }
};