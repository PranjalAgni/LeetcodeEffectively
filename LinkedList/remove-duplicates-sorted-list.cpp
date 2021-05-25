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
    ListNode* deleteDuplicates(ListNode* head) {
        unordered_map<int, int> hashMap;
        ListNode* prevHead = NULL;
        ListNode* curr = head;
        while (curr != NULL) {
            hashMap[curr->val] += 1;
            if (hashMap[curr->val] > 1) {
                ListNode* deleteNode = curr;
                if (prevHead) prevHead->next = curr->next;
                deleteNode = NULL;
            } else {
                prevHead = curr;
            }
            curr = curr->next;
        }

        return head;
    }
};