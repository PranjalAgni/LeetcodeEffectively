/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */

bool isSameTree(Tree* root1, Tree* root2) {
    if (root1 == NULL && root2 == NULL) return true;
    if (root1 == NULL || root2 == NULL) return false;

    if (root1->val != root2->val) return false;

    bool isSame = isSameTree(root1->left, root2->left) &&
                  isSameTree(root1->right, root2->right);

    return isSame;
}

bool solve(Tree* root, Tree* target) {
    if (root == NULL || target == NULL) return false;
    if (root->val == target->val) {
        if (isSameTree(root, target)) return true;
    }

    bool status = solve(root->left, target) || solve(root->right, target);
    return status;
}