// VVI question, on linkedlist basics
// Recursion + Reverse a Linked List

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
    ListNode* reverseInKBatch(ListNode* head, int K, int len) {
        ListNode* newHead = NULL;
        ListNode* currNode = head;

        int groupSize = len - K;
        if (groupSize < 0) return head;
        int count = K;
        while (currNode != NULL && count-- > 0) {
            ListNode* nextNode = currNode->next;
            currNode->next = newHead;
            newHead = currNode;
            currNode = nextNode;
        }

        if (currNode != NULL) {
            head->next = reverseInKBatch(currNode, K, len - K);
        }

        return newHead;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = 0;
        ListNode* temp = head;

        while (temp != NULL) {
            len += 1;
            temp = temp->next;
        }

        return reverseInKBatch(head, k, len);
    }
};