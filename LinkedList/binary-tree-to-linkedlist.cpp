/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */

/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */

void inorder(Tree* root, LLNode** head) {
    if (!root) return;
    inorder(root->left, head);
    (*head)->next = new LLNode(root->val);
    *head = (*head)->next;
    inorder(root->right, head);
}

LLNode* solve(Tree* root) {
    LLNode* newList = new LLNode(-1);
    LLNode* newHead = newList;
    inorder(root, &newHead);
    return newList->next;
}