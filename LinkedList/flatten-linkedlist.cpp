/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
   public:
    Node* flattenRec(Node* head) {
        Node* curr = head;
        Node* tail = head;

        while (curr) {
            Node* child = curr->child;
            Node* nextNode = curr->next;

            if (child) {
                Node* childTail = flattenRec(child);
                curr->next = child;
                child->prev = curr;
                childTail->next = nextNode;
                if (nextNode) nextNode->prev = childTail;
                curr->child = NULL;
                curr = tail;
            } else {
                curr = nextNode;
            }

            if (curr) tail = curr;
        }

        return tail;
    }

    Node* flatten(Node* head) {
        if (head) flattenRec(head);
        return head;
    }
};