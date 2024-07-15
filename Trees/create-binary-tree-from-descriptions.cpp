// https://leetcode.com/problems/create-binary-tree-from-descriptions/

// Time: O(N) | Space: O(N)
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodesMap;
        unordered_map<int, bool> childNodes;
        for (vector<int>& description: descriptions) {
          int parent = description[0];
          int child = description[1];
          bool isLeft = description[2] == 1;
          
          TreeNode* parentNode = NULL;
          TreeNode* childNode = NULL;
          if (nodesMap.find(parent) != nodesMap.end()) {
            parentNode = nodesMap[parent];
          }
          
          if (nodesMap.find(child) != nodesMap.end()) {
            childNode = nodesMap[child];
          }
          
          if (!parentNode) parentNode = new TreeNode(parent);
          if (!childNode) childNode = new TreeNode(child);
          
          childNodes[child] = true;
          
          if (isLeft) parentNode->left = childNode;
          else parentNode->right = childNode;
          
          nodesMap[parent] = parentNode;
          nodesMap[child] = childNode;
        }
      
        TreeNode* answer = NULL;
      
        for (auto const& it: nodesMap) {
          if (!childNodes[it.first]) {
            answer = it.second;
            break;
          }
        }
        return answer;
    }
};