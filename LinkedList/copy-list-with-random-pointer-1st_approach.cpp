// 1. Mantained two hashMaps
// 2. One to store node vs position of node in the given list to get position of
// random node in constant time
// 3. And one position vs node to get the random node in constant time

class Solution {
   public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, int> nodeToPos;
        Node* temp = head;
        int idx = 0;
        while (temp != NULL) {
            nodeToPos[temp] = idx;
            temp = temp->next;
            idx += 1;
        }

        Node* newNode = new Node(-1);
        Node* newHead = newNode;
        unordered_map<int, Node*> posToNode;
        idx = 0;
        temp = head;
        while (temp != NULL) {
            Node* newCurrNode = new Node(temp->val);
            newNode->next = newCurrNode;
            newNode = newNode->next;
            posToNode[idx] = newNode;
            temp = temp->next;
            idx += 1;
        }

        temp = newHead->next;

        while (temp != NULL) {
            temp->random = posToNode[nodeToPos[head->random]];
            if (!head->random) temp->random = NULL;
            temp = temp->next;
            head = head->next;
        }

        return newHead->next;
    }
};