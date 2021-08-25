/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */
LLNode* solve(LLNode* node, int i, int j) {
    LLNode* startPrev = NULL;
    LLNode* startNode = node;
    int pos = i;

    while (startNode != NULL && pos-- > 0) {
        startPrev = startNode;
        startNode = startNode->next;
    }

    LLNode* startHead = startNode;
    LLNode* newHead = NULL;
    int times = j - i + 1;

    while (startNode != NULL && times-- > 0) {
        LLNode* nextNode = startNode->next;
        startNode->next = newHead;
        newHead = startNode;
        startNode = nextNode;
    }

    if (startPrev) {
        startPrev->next = newHead;
    } else {
        node = newHead;
    }

    startHead->next = startNode;
    return node;
}