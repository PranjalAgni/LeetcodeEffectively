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
        ListNode* temp = head;
        while (temp != NULL) {
            len += 1;
            temp = temp->next;
        }

        k = k % len;
        while (k-- > 0) {
            ListNode* prev = NULL;
            ListNode* curr = head;

            while (curr->next != NULL) {
                prev = curr;
                curr = curr->next;
            }

            if (!prev) break;
            prev->next = NULL;
            curr->next = head;
            head = curr;
        }

        return head;
    }
};