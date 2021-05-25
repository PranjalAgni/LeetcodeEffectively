// 1. fining first node which is >= x
// 2. targetPrev contains prev node of targetNode
// 3. targetNode is the node before which we need to store node < x
// 4. startPrev = NULL & startHead = targetNode->next
// 5 when we find a node < x we delete it from there (thatNode)
// 6. And store it in targetPrev->next = thatnode & targetPrev =
// targetPrev->next
class Solution {
   public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* targetPrev = NULL;
        ListNode* targetNode = head;

        while (targetNode != NULL && targetNode->val < x) {
            targetPrev = targetNode;
            targetNode = targetNode->next;
        }

        ListNode* startPrev = targetNode;
        ListNode* startHead = NULL;
        if (targetNode) startHead = targetNode->next;

        while (startHead != NULL) {
            if (startHead->val < x) {
                ListNode* moveNode = startHead;
                if (startPrev)
                    startPrev->next = startHead->next;
                else
                    startPrev->next = NULL;
                if (targetPrev) {
                    targetPrev->next = moveNode;
                    targetPrev = targetPrev->next;
                } else {
                    ListNode* newHead = moveNode;
                    newHead->next = head;
                    head = newHead;
                    targetPrev = head;
                }

                targetPrev->next = targetNode;
            }

            startPrev = startHead;
            startHead = startHead->next;
        }

        return head;
    }
};