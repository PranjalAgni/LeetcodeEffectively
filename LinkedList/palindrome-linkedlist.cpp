using namespace std;

// This is an input struct. Do not edit.
class LinkedList {
   public:
    int value;
    LinkedList* next;

    LinkedList(int value) {
        this->value = value;
        this->next = nullptr;
    }
};

LinkedList* getMiddleNode(LinkedList* head) {
    LinkedList* slow = head;
    LinkedList* fast = head;
    LinkedList* prev = NULL;
    while (fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    return prev;
}

LinkedList* reverseLinkedList(LinkedList* head) {
    LinkedList* newHead = NULL;

    while (head != NULL) {
        LinkedList* nextNode = head->next;
        head->next = newHead;
        newHead = head;
        head = nextNode;
    }

    return newHead;
}

// Time: O(N) | Space: O(1)
bool linkedListPalindrome(LinkedList* head) {
    if (!head->next) return true;
    LinkedList* middle = getMiddleNode(head);
    if (!middle) return false;
    LinkedList* head2 = middle->next;
    if (middle) middle->next = NULL;
    head2 = reverseLinkedList(head2);
    while (head != NULL && head2 != NULL) {
        if (head->value != head2->value) return false;
        head = head->next;
        head2 = head2->next;
    }

    return true;
}
