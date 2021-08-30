// Time: O(H) | Space: O(H)
// H height of BST
void inorderSuccessor(Tree* root, int t, int& ans, bool& isFound) {
    if (root == NULL) return;
    inorderSuccessor(root->left, t, ans, isFound);
    if (root->val > t && !isFound) {
        isFound = true;
        ans = root->val;
        return;
    }
    inorderSuccessor(root->right, t, ans, isFound);
}

int solve(Tree* root, int t) {
    int ans;
    bool isFound = false;
    inorderSuccessor(root, t, ans, isFound);
    return ans;
}