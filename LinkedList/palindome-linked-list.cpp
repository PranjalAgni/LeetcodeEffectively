// Time: O(N) | Space: O(N)
// N = number of nodes in linkedlist
bool solve(LLNode* node) {
    LLNode* newNode = new LLNode(-1);
    LLNode* newNodeHead = newNode;
    LLNode* runnerNode = node;

    while (runnerNode != NULL) {
        newNodeHead->next = new LLNode(runnerNode->val);
        newNodeHead = newNodeHead->next;
        runnerNode = runnerNode->next;
    }

    LLNode* newHead = NULL;
    newNode = newNode->next;

    while (newNode != NULL) {
        LLNode* nextNode = newNode->next;
        newNode->next = newHead;
        newHead = newNode;
        newNode = nextNode;
    }

    runnerNode = node;

    while (runnerNode != NULL && newHead != NULL) {
        if (runnerNode->val != newHead->val) return false;
        runnerNode = runnerNode->next;
        newHead = newHead->next;
    }

    return true;
}