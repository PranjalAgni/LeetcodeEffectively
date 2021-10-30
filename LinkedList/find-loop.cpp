#include <vector>
using namespace std;

class LinkedList {
   public:
    int value;
    LinkedList *next;

    LinkedList(int value);
};

// Time: O(NK) | Space: O(1)
// N = number of nodes
// K = number of cycles, to check for the loop
LinkedList *findLoop(LinkedList *head) {
    LinkedList *slow = head;
    LinkedList *fast = head;

    // find if the loop exists
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }

    // reinitalizing slow to head
    slow = head;

    // iterating till we find where the loop is made
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}
