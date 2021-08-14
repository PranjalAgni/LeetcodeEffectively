/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */

void mergeHelper(Tree* node0, Tree* node1, Tree** current) {
    if (!node0 && !node1) return;
    int val = 0;
    if (node0) val += node0->val;
    if (node1) val += node1->val;
    *current = new Tree(val);
    Tree* node0Left = node0 ? node0->left : NULL;
    Tree* node0Right = node0 ? node0->right : NULL;
    Tree* node1Left = node1 ? node1->left : NULL;
    Tree* node1Right = node1 ? node1->right : NULL;

    mergeHelper(node0Left, node1Left, &(*current)->left);
    mergeHelper(node0Right, node1Right, &(*current)->right);
}

Tree* solve(Tree* node0, Tree* node1) {
    if (!node0) return node1;
    if (!node1) return node0;
    Tree* newHead = new Tree(-1);
    mergeHelper(node0, node1, &newHead);
    return newHead;
}