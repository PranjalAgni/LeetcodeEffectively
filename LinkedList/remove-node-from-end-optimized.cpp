
class Solution {
   public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* newHead = new ListNode(-1);
        newHead->next = head;

        ListNode* slow = newHead;
        ListNode* fast = newHead;

        while (fast != NULL && n-- > 0) {
            fast = fast->next;
        }

        if (fast == NULL) return newHead->next;

        while (fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }

        if (slow == newHead)
            newHead->next = head->next;
        else
            slow->next = slow->next->next;

        return newHead->next;
    }
};
