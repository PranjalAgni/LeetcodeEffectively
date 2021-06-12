using namespace std;

class Node {
   public:
    int value;
    Node *prev;
    Node *next;

    Node(int value);
};

// Feel free to add new properties and methods to the class.
class DoublyLinkedList {
   public:
    Node *head;
    Node *tail;

    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void setHead(Node *node) {
        if (!head) {
            head = node;
            tail = node;
            return;
        }

        insertBefore(head, node);
    }

    void setTail(Node *node) {
        if (!tail) {
            setHead(node);
            return;
        }

        insertAfter(tail, node);
    }

    void insertBefore(Node *node, Node *nodeToInsert) {
        if (nodeToInsert == head && nodeToInsert == tail) return;
        remove(nodeToInsert);
        nodeToInsert->prev = node->prev;
        nodeToInsert->next = node;

        if (!node->prev) {
            head = nodeToInsert;
        } else {
            node->prev->next = nodeToInsert;
        }

        node->prev = nodeToInsert;
    }

    void insertAfter(Node *node, Node *nodeToInsert) {
        if (nodeToInsert == head && nodeToInsert == tail) return;
        remove(nodeToInsert);
        nodeToInsert->prev = node;
        nodeToInsert->next = node->next;

        if (!node->next) {
            tail = nodeToInsert;
        } else {
            node->next->prev = nodeToInsert;
        }
        node->next = nodeToInsert;
    }

    void insertAtPosition(int position, Node *nodeToInsert) {
        if (position == 1) {
            setHead(nodeToInsert);
            return;
        }

        Node *node = head;
        int currPos = 1;

        while (node != nullptr && currPos != position) {
            node = node->next;
            currPos += 1;
        }

        if (node != nullptr) {
            insertBefore(node, nodeToInsert);
        } else {
            setTail(nodeToInsert);
        }
    }

    void removeNodesWithValue(int value) {
        Node *node = head;
        while (node) {
            Node *nodeToRemove = node;
            node = node->next;
            if (nodeToRemove->value == value) {
                remove(nodeToRemove);
            }
        }
    }

    void remove(Node *node) {
        if (node == head) head = head->next;
        if (node == tail) tail = tail->prev;

        removeNodeBindings(node);
    }

    bool containsNodeWithValue(int value) {
        Node *curr = head;

        while (curr != NULL && curr->value != value) {
            curr = curr->next;
        }

        return curr != nullptr;
    }

    void removeNodeBindings(Node *node) {
        if (node->prev) {
            node->prev->next = node->next;
        }
        if (node->next) {
            node->next->prev = node->prev;
        }

        node->prev = NULL;
        node->next = NULL;
    }
};
