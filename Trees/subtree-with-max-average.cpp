/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */

struct TreeInfo {
    double numNodes;
    double sum;
};

TreeInfo subTreeMaxAvgUtil(Tree* root, double& answer) {
    if (root == NULL) return TreeInfo{0, 0};
    TreeInfo leftTreeInfo = subTreeMaxAvgUtil(root->left, answer);
    TreeInfo rightTreeInfo = subTreeMaxAvgUtil(root->right, answer);

    double totalNodes = 1 + leftTreeInfo.numNodes + rightTreeInfo.numNodes;
    double nodesSum = leftTreeInfo.sum + rightTreeInfo.sum + root->val;
    double avg = (double)(nodesSum / totalNodes);
    if (avg > answer) answer = avg;
    return TreeInfo{totalNodes, nodesSum};
}

double solve(Tree* root) {
    double answer = 0;
    subTreeMaxAvgUtil(root, answer);
    return answer;
}