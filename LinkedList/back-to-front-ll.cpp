
LLNode* solve(LLNode* node) {
    int nodes = 0;
    LLNode* curr = node;
    while (curr != NULL) {
        nodes += 1;
        curr = curr->next;
    }

    int mid = nodes / 2;
    if (mid == 0) return node;
    LLNode* startNode = node;
    LLNode* startPrev = NULL;

    while (startNode != NULL && mid-- > 0) {
        startPrev = startNode;
        startNode = startNode->next;
    }

    LLNode* newHead = NULL;

    while (startNode != NULL) {
        LLNode* nextNode = startNode->next;
        startNode->next = newHead;
        newHead = startNode;
        startNode = nextNode;
    }

    if (startPrev) startPrev->next = NULL;

    LLNode* newListHead = new LLNode(-1);
    LLNode* newListCurr = newListHead;

    while (newHead != NULL || node != NULL) {
        if (newHead) {
            newListCurr->next = new LLNode(newHead->val);
            newListCurr = newListCurr->next;
        }
        if (node) {
            newListCurr->next = new LLNode(node->val);
            newListCurr = newListCurr->next;
        }

        if (newHead) newHead = newHead->next;
        if (node) node = node->next;
    }

    return newListHead->next;
}