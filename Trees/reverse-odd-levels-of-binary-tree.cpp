// https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/

// Took a long time to solve this, interesting BFS problem to ask
// Time: O(N) | Space: O(1)
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> nodesQueue;
        vector<int> nodesVal;
        nodesQueue.push(root);
        int levelIdx = 0;
        while (!nodesQueue.empty()) {
            int size = nodesQueue.size();
            vector<int> levelNodes;
            
            for (int idx = 0; idx < size; idx++) {
                TreeNode* node = nodesQueue.front();
                nodesQueue.pop();
                
                if (levelIdx % 2 != 0) {
                    node->val = nodesVal[size - idx - 1]; 
                }
                
                if (node->left) {
                   nodesQueue.push(node->left);
                   levelNodes.push_back(node->left->val);
                }
                
                if (node->right) {
                   nodesQueue.push(node->right);
                   levelNodes.push_back(node->right->val);
                }
            }
            
            levelIdx += 1;
            nodesVal = levelNodes;
        }
        
        return root;
    }
};