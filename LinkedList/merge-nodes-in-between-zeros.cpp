// https://leetcode.com/problems/merge-nodes-in-between-zeros/
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
// Time: O(N) | Space: O(N)
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
      ListNode* temp = head;
      ListNode* newHead = new ListNode(-1);
      ListNode* newHeadTemp = newHead;
      int sum = 0;
      bool isZeroMarked = false;
      
      while (temp != NULL) {
        // updating zero pos
        if (temp->val == 0) {
          if (isZeroMarked) {
            newHeadTemp->next = new ListNode(sum);
            newHeadTemp = newHeadTemp->next;
            sum = 0;
          }
          
          isZeroMarked = true;
        }
        
        sum += temp->val;
        temp = temp->next;
      }
      
      return newHead->next;
      
    }
};