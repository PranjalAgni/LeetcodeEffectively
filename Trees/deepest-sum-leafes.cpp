// https://leetcode.com/problems/deepest-leaves-sum/

// Structure to hold node information
struct NodeInfo {
  int height;
  int val;
};

class Solution {
private:
    // Time: O(N) | Space: O(1)
    // N = number of nodes in the tree
    void findDeepestLeaves(TreeNode* root, vector<NodeInfo>& leafTreeNodes, int& maxHeightForLeaf, int height) {
      if (!root) return;
      if (!root->left && !root->right) {
        struct NodeInfo nodeInfo = {height, root->val};
        leafTreeNodes.push_back(nodeInfo);
      }
      maxHeightForLeaf = max(maxHeightForLeaf, height);
      
      findDeepestLeaves(root->left, leafTreeNodes, maxHeightForLeaf, height + 1);
      
      findDeepestLeaves(root->right, leafTreeNodes, maxHeightForLeaf, height + 1);
    } 
public:
    // Time: O(N) | Space: O(N)
    // N = number of nodes in the tree
    int deepestLeavesSum(TreeNode* root) {
        vector<NodeInfo> leafTreeNodes;
        int maxHeightForLeaf = 0;
        findDeepestLeaves(root, leafTreeNodes, maxHeightForLeaf, 0);
        int sum = 0;
        for (NodeInfo& nodeInfo: leafTreeNodes) {          
          if (nodeInfo.height == maxHeightForLeaf) {
            sum += nodeInfo.val;
          }
        }
      
        return sum;
    }
};