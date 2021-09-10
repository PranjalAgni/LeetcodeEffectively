/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */
// Time: O(N) | Space: O(1)
LLNode* solve(LLNode* node, int k) {
    if (!node) return node;
    LLNode* newHead = NULL;
    int temp = k;
    LLNode* current = node;

    while (current != NULL && temp-- > 0) {
        LLNode* nextNode = current->next;
        current->next = newHead;
        newHead = current;
        current = nextNode;
    }

    node->next = solve(current, k);
    return newHead;
}