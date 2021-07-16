#include <vector>
using namespace std;

class LinkedList {
   public:
    int value;
    LinkedList* next;

    LinkedList(int value);
    void addMany(vector<int> values);
    vector<int> getNodesInArray();
};

void removeKthNodeFromEnd(LinkedList* head, int k) {
    int N = 0;
    LinkedList* curr = head;

    while (curr != NULL) {
        N += 1;
        curr = curr->next;
    }

    int nodePos = N - k;
    LinkedList* prev = NULL;
    curr = head;

    while (nodePos-- > 0) {
        prev = curr;
        curr = curr->next;
    }

    if (prev == NULL)
        *head = *head->next;
    else {
        LinkedList* targetNode = curr;
        prev->next = curr->next;
        targetNode = NULL;
    }
}
