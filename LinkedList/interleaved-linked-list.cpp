/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */
LLNode* solve(LLNode* l0, LLNode* l1) {
    LLNode* interleavedList = new LLNode(-1);
    LLNode* newHead = interleavedList;

    int listLeft = 0;
    while (l0 != NULL || l1 != NULL) {
        if (listLeft == 1) {
            LLNode* left = l0 ? l0 : l1;
            newHead->next = left;
            break;
        }
        if (l0) {
            newHead->next = new LLNode(l0->val);
            newHead = newHead->next;
            l0 = l0->next;
            listLeft += 1;
        }
        if (l1) {
            newHead->next = new LLNode(l1->val);
            newHead = newHead->next;
            l1 = l1->next;
            listLeft += 1;
        }

        if (listLeft == 2) listLeft = 0;
    }

    return interleavedList->next;
}