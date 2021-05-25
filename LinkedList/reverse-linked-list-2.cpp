// 1. Get the startNode (left) and startPrev
// 2. Get the endNode (right)
// 3. remNode = endNode->next
// 4. Store ref of startNode:  startHead = startNode;
// 5. Reverse list from startNode to endNode (right - left + 1)
// 6 startPrev->next = newHead;
// 5. startHead->next = remNode
// 6. return head;
class Solution {
   public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;

        ListNode* startNode = head;
        ListNode* startPrev = NULL;
        int count = left - 1;

        while (startNode != NULL && count-- > 0) {
            startPrev = startNode;
            startNode = startNode->next;
        }

        ListNode* newHead = NULL;
        ListNode* startHead = startNode;
        count = right - left + 1;

        while (startNode != NULL && count-- > 0) {
            ListNode* nextNode = startNode->next;
            startNode->next = newHead;
            newHead = startNode;
            startNode = nextNode;
        }

        if (startPrev)
            startPrev->next = newHead;
        else
            head = newHead;
        startHead->next = startNode;

        return head;
    }
};