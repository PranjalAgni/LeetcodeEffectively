// https://leetcode.com/problems/distribute-coins-in-binary-tree/

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
struct TreeInfo {
    int subTreeSize;
    int numCoins;
};

// Time: O(N) | Space: O(N)
class Solution {
private:
    TreeInfo computeDistributionRecursive(TreeNode* root, int& answer) {
        if (!root) return TreeInfo {0, 0};
        TreeInfo leftSubtree = computeDistributionRecursive(root->left, answer);
        TreeInfo rightSubtree = computeDistributionRecursive(root->right, answer);
        
        int currentHeight = 1 + leftSubtree.subTreeSize + rightSubtree.subTreeSize;
        int currentCoins = root->val + leftSubtree.numCoins + rightSubtree.numCoins;
        answer += abs(leftSubtree.subTreeSize - leftSubtree.numCoins) + abs(rightSubtree.subTreeSize - rightSubtree.numCoins);
        
        return {currentHeight, currentCoins};
    }   
public: 
    int distributeCoins(TreeNode* root) {
        int answer = 0;
        TreeInfo result = computeDistributionRecursive(root, answer);
        return answer;
    }
};