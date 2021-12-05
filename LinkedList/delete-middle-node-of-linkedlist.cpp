// https://leetcode.com/contest/weekly-contest-270/problems/delete-the-middle-node-of-a-linked-list/

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
private:
  ListNode* getPreviousMiddleNode(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* slow = head;
    ListNode* fast = head;
    
    while (fast != NULL && fast->next != NULL) {
      prev = slow;
      slow = slow->next;
      fast = fast->next->next;
    }
    
    return prev;
  }
public:
    // Time: O(N) | Space: O(1)
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* prevMiddleNode = getPreviousMiddleNode(head);
        if(!prevMiddleNode) return NULL; // if there is only one node
        if(prevMiddleNode && prevMiddleNode->next) prevMiddleNode->next = prevMiddleNode->next->next;
        return head;
    }
};