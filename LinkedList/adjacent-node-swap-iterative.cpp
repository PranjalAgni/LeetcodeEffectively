using namespace std;

// This is an input struct. Do not edit.
class LinkedList {
   public:
    int value;
    LinkedList* next = nullptr;

    LinkedList(int value) { this->value = value; }
};

// Time: O(N) | Space: O(1)
LinkedList* nodeSwap(LinkedList* head) {
    if (!head || !head->next) return head;
    LinkedList* previous = new LinkedList(-1);
    previous->next = head;
    LinkedList* temp = previous;

    while (previous->next != NULL && previous->next->next != NULL) {
        LinkedList* first = previous->next;
        LinkedList* second = previous->next->next;
        first->next = second->next;
        second->next = first;
        previous->next = second;
        previous = first;
    }

    return temp->next;
}
