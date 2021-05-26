class Solution {
   public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int startPos = a;
        int endPos = b - a + 1;

        ListNode* startPrev = NULL;
        ListNode* temp = list1;

        int idx = 0;
        // Get the previous of ath node and the bth node
        while (temp != NULL && b-- >= 0) {
            if (idx == a - 1) startPrev = temp;  // has ath previous node
            temp = temp->next;                   // has bth node
            idx += 1;
        }

        // connect to head of list 2
        startPrev->next = list2;

        ListNode* lastNodeB = list2;

        // Get the lastNode of list2
        while (lastNodeB->next != NULL) {
            lastNodeB = lastNodeB->next;
        }

        // connect lastNode of list2 to remaning nodes of listA
        lastNodeB->next = temp;

        return list1;
    }
};