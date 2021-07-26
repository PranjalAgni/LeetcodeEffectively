using namespace std;

// This is an input struct. Do not edit.
class LinkedList {
   public:
    int value;
    LinkedList *next = nullptr;

    LinkedList(int value) { this->value = value; }
};

LinkedList *sumOfLinkedLists(LinkedList *linkedListOne,
                             LinkedList *linkedListTwo) {
    if (!linkedListOne && !linkedListTwo) return NULL;
    if (!linkedListOne) return linkedListTwo;
    if (!linkedListTwo) return linkedListOne;

    int carry = 0;
    LinkedList *head = linkedListOne;
    LinkedList *prev = NULL;
    while (linkedListOne != NULL && linkedListTwo != NULL) {
        int sum = carry + linkedListOne->value + linkedListTwo->value;
        carry = sum / 10;
        sum = sum % 10;
        linkedListOne->value = sum;
        prev = linkedListOne;
        linkedListOne = linkedListOne->next;
        linkedListTwo = linkedListTwo->next;
    }

    while (linkedListOne != NULL) {
        int sum = carry + linkedListOne->value;
        carry = sum / 10;
        sum = sum % 10;
        linkedListOne->value = sum;
        linkedListOne = linkedListOne->next;
    }

    while (linkedListTwo != NULL) {
        int sum = carry + linkedListTwo->value;
        carry = sum / 10;
        sum = sum % 10;
        LinkedList *newNode = new LinkedList(sum);
        prev->next = newNode;
        prev = prev->next;
        linkedListTwo = linkedListTwo->next;
    }

    if (carry) {
        LinkedList *newNode = new LinkedList(carry);
        prev->next = newNode;
        prev = prev->next;
    }

    return head;
}