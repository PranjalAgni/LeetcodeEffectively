/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */

void mergeHelper(Tree** node0, Tree* node1) {
    if (!*node0 && !node1) return;
    if (*node0 && node1) (*node0)->val += node1->val;

    if (*node0 && node1) {
        mergeHelper(&(*node0)->left, node1->left);
        mergeHelper(&(*node0)->right, node1->right);
    } else if (node1) {
        *node0 = node1;
    }
}

Tree* solve(Tree* node0, Tree* node1) {
    if (!node0) return node1;
    if (!node1) return node0;
    Tree* newHead = node0;
    mergeHelper(&node0, node1);
    return newHead;
}