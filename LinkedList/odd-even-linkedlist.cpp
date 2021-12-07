// https://leetcode.com/problems/odd-even-linked-list

class Solution {
public:
    // Time: O(N) | Space: O(N)
    ListNode* oddEvenListSpace(ListNode* head) {
        ListNode* oddListHead = new ListNode(-1);
        ListNode* evenListHead = new ListNode(-1);
        ListNode* runnerNode = head;
      
        ListNode* oddList = oddListHead;
        ListNode* evenList = evenListHead;
        int idx = 0;
        while (runnerNode != NULL) {
          int val = runnerNode->val;
          if (idx % 2 == 0) {
            evenList->next = new ListNode(val);
            evenList = evenList->next;
          } else {
            oddList->next = new ListNode(val);
            oddList = oddList->next;
          }
          
          runnerNode = runnerNode->next;
          idx += 1;
        }
        
        evenList->next = oddListHead->next;
        return evenListHead->next;
    }
    
    // Time: O(N) | Space: O(1)
    ListNode* oddEvenList(ListNode* head) {
      if (!head) return NULL;
      ListNode* oddHead = head;
      ListNode* evenHead = head->next;
      ListNode* oddNode = oddHead;
      ListNode* evenNode = evenHead;
      
      while (evenNode != NULL && evenNode->next != NULL) {
        oddNode->next = evenNode->next;
        oddNode = oddNode->next;
        evenNode->next = oddNode->next;
        evenNode = evenNode->next; 
      }
      
      oddNode->next = evenHead;
      return oddHead;
    }
};
