// 1. Get startPos = K
// 2. Get endPos = len - K + 1
// 3. if startPos == endPos return head;
// 4. Get startNode and endNode
// 5. swap the values
// 6. Return the head;
class Solution {
   public:
    ListNode* swapNodes(ListNode* head, int k) {
        int len = 0;
        ListNode* temp = head;

        while (temp != NULL) {
            temp = temp->next;
            len += 1;
        }

        int startPos = k;
        int endPos = len - k + 1;
        if (startPos == endPos) return head;

        ListNode* startHead = head;
        ListNode* endHead = head;
        while (startHead != NULL && startPos-- > 1) {
            startHead = startHead->next;
        }

        while (endHead != NULL && endPos-- > 1) {
            endHead = endHead->next;
        }

        int val = startHead->val;
        startHead->val = endHead->val;
        endHead->val = val;

        return head;
    }
};