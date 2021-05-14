/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
   public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;

        int len = 0;
        ListNode* curr = head;
        while (curr != NULL) {
            len += 1;
            curr = curr->next;
        }

        k = k % len;
        if (len == 1 || k == 0) return head;

        int idxFromStart = len - k;

        ListNode* prev = NULL;
        curr = head;
        while (curr != NULL && idxFromStart-- > 0) {
            prev = curr;
            curr = curr->next;
        }

        prev->next = NULL;

        // Reusing pointer
        prev = curr;
        while (prev->next != NULL) {
            prev = prev->next;
        }

        prev->next = head;
        head = curr;

        return head;
    }
};