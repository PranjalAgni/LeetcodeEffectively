// https://leetcode.com/problems/binary-tree-level-order-traversal/

class Solution {
public:
    // Time: O(N) | Space: O(N)
    // N = number of nodes
    vector<vector<int>> levelOrder(TreeNode* root) {
      if (!root) return {};
      queue<TreeNode*> nodesQueue;
      nodesQueue.push(root);
      vector<vector<int>> answer;
      
      while (!nodesQueue.empty()) {
        vector<int> currentLevel;
        queue<TreeNode*> nextNodesQueue;
        
        while (!nodesQueue.empty()) {
          TreeNode* node = nodesQueue.front();
          nodesQueue.pop();
          if (node->left) nextNodesQueue.push(node->left);
          if (node->right) nextNodesQueue.push(node->right);
          currentLevel.push_back(node->val);
        }
        
        nodesQueue = nextNodesQueue;
        if (currentLevel.size() > 0) {
          answer.push_back(currentLevel);
        }
      }
      
      return answer; 
    }
};