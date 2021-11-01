using namespace std;

// This is an input struct. Do not edit.
class LinkedList {
   public:
    int value;
    LinkedList *next = nullptr;

    LinkedList(int value) { this->value = value; }
};

// Time: O(N) | Space: O(N)
LinkedList *nodeSwap(LinkedList *head) {
    if (!head || !head->next) return head;
    LinkedList *nextNode = head->next;
    head->next = nodeSwap(head->next->next);
    nextNode->next = head;
    return nextNode;
}
