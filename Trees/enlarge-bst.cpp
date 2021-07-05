/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */

void inorder(Tree* root, vector<int>& inorderNode) {
    if (root == NULL) return;
    inorder(root->left, inorderNode);
    inorderNode.push_back(root->val);
    inorder(root->right, inorderNode);
}

void enlargeTree(Tree* root, vector<int>& inorderNode, vector<int>& prefixSum) {
    if (root == NULL) return;
    vector<int>::iterator it =
        lower_bound(inorderNode.begin(), inorderNode.end(), root->val);
    int idx = it - inorderNode.begin();
    root->val += prefixSum[prefixSum.size() - 1] - prefixSum[idx];
    enlargeTree(root->left, inorderNode, prefixSum);
    enlargeTree(root->right, inorderNode, prefixSum);
}

vector<int> getPrefixSum(vector<int>& inorderNode) {
    int N = inorderNode.size();
    vector<int> prefixSum(N, 0);
    prefixSum[0] = inorderNode[0];

    for (int idx = 1; idx < N; idx++) {
        prefixSum[idx] = prefixSum[idx - 1] + inorderNode[idx];
    }

    return prefixSum;
}

Tree* solve(Tree* root) {
    if (!root) return root;
    vector<int> inorderNode;
    inorder(root, inorderNode);
    vector<int> prefixSum = getPrefixSum(inorderNode);
    enlargeTree(root, inorderNode, prefixSum);

    return root;
}