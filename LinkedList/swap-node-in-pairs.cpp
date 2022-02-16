// https://leetcode.com/problems/swap-nodes-in-pairs/

class Solution {
public:
    // Time: O(N) | Space: O(1)
    ListNode* swapPairs(ListNode* head) {
       if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* remaning = head->next->next;
        ListNode* newhead = head->next;
        head->next->next = head;
        head->next = swapPairs(remaning);
        return newhead;
    }
};