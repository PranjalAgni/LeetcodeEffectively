/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */

int search(vector<int>& inorder, int low, int high, int target) {
    for (int idx = low; idx <= high; idx++) {
        if (inorder[idx] == target) return idx;
    }

    return -1;
}

Tree* constructTree(vector<int>& preorder, vector<int>& inorder, int low,
                    int high, int& pos) {
    if (pos >= preorder.size()) return NULL;
    if (low > high) return NULL;

    Tree* root = new Tree(preorder[pos]);
    pos += 1;

    if (low == high) return root;

    int inorderPos = search(inorder, low, high, root->val);
    root->left = constructTree(preorder, inorder, low, inorderPos - 1, pos);
    root->right = constructTree(preorder, inorder, inorderPos + 1, high, pos);
    return root;
}
Tree* solve(vector<int>& preorder, vector<int>& inorder) {
    int pos = 0;
    return constructTree(preorder, inorder, 0, inorder.size() - 1, pos);

} /**
   * class Tree {
   *     public:
   *         int val;
   *         Tree *left;
   *         Tree *right;
   * };
   */

int search(vector<int>& inorder, int low, int high, int target) {
    for (int idx = low; idx <= high; idx++) {
        if (inorder[idx] == target) return idx;
    }

    return -1;
}

Tree* constructTree(vector<int>& preorder, vector<int>& inorder, int low,
                    int high, int& pos) {
    if (pos >= preorder.size()) return NULL;
    if (low > high) return NULL;

    Tree* root = new Tree(preorder[pos]);
    pos += 1;

    if (low == high) return root;

    int inorderPos = search(inorder, low, high, root->val);
    root->left = constructTree(preorder, inorder, low, inorderPos - 1, pos);
    root->right = constructTree(preorder, inorder, inorderPos + 1, high, pos);
    return root;
}
Tree* solve(vector<int>& preorder, vector<int>& inorder) {
    int pos = 0;
    return constructTree(preorder, inorder, 0, inorder.size() - 1, pos);
}