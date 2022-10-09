// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

class Solution {
private:
    bool findTargetHelper(TreeNode* root, int target, unordered_set<int>& hashSet) {
        if (!root) return false;
        if (hashSet.find(target - root->val) != hashSet.end()) return true;
        hashSet.insert(root->val);
        return findTargetHelper(root->left, target, hashSet) || findTargetHelper(root->right, target, hashSet);
    }
public:
    // Time: O(N) | Space: O(N)
    // N = number of nodes in the tree
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        unordered_set<int> hashSet;
        return findTargetHelper(root, k, hashSet);
    }
};