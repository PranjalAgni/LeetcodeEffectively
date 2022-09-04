// https://leetcode.com/problems/average-of-levels-in-binary-tree/

class Solution {
public:
    // Time: O(N) | Space: O(N)
    // Simple BFS solution 
    // implementation via queue
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> nodeQ;
        vector<double> answer;
        nodeQ.push(root);
        while (!nodeQ.empty()) {
          queue<TreeNode*> childNodeQ;
          int N = nodeQ.size();
          double currentSum = 0;
          for (int idx = 0; idx < N; idx++) {
            TreeNode* current = nodeQ.front();
            nodeQ.pop();
            currentSum += current->val;
            if (current->left) childNodeQ.push(current->left);
            if (current->right) childNodeQ.push(current->right);
          }
          
          answer.push_back(currentSum / N);
          nodeQ = childNodeQ;
        }
      
        return answer;
    }
};