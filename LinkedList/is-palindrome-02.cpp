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
    bool isPalindrome(ListNode* head) {
        if (head == NULL) return false;
        if (head->next == NULL) return true;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* newHead = NULL;
        ListNode* curr = slow->next;

        while (curr != NULL) {
            ListNode* nextNode = curr->next;
            curr->next = newHead;
            newHead = curr;
            curr = nextNode;
        }

        ListNode* runningA = head;
        ListNode* runningB = newHead;

        while (runningA != NULL && runningB != NULL) {
            if (runningA->val != runningB->val) return false;
            runningA = runningA->next;
            runningB = runningB->next;
        }

        return true;
    }
};