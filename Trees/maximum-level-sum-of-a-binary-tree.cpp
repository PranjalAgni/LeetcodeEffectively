// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/?envType=daily-question&envId=2026-01-06

// TC: O(V + E) | Space: O(V)
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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int maxSum = INT_MIN;
        int maxLevel = 0;
        int level = 1;
        while (!q.empty()) {
            queue<TreeNode*> current;
            int sum = 0;
            while (!q.empty()) {
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;

                if(node->left) current.push(node->left);
                if (node->right) current.push(node->right);
            }

            if (sum > maxSum) {
                maxSum = sum;
                maxLevel = level;
            }

            q = current;
            level += 1;
        }

        return maxLevel;
    }
};