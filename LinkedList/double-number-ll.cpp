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
// This is a slow solution, we can do it in one pass without reversing
// TC: O(N) | SC: O(N)
// N = number of nodes
class Solution {
private:
  ListNode* reverse(ListNode* head) {
    ListNode* newHead = NULL;
    while (head != NULL) {
      ListNode* nextNode = head->next;
      head->next = newHead;
      newHead = head;
      head = nextNode;
    }
    
    return newHead;
  }
public:
    ListNode* doubleIt(ListNode* head) {
        ListNode* temp = head;
        vector<int> list;
      
        while (temp != NULL) {
          list.push_back(temp->val);
          temp = temp->next;
        }
      
        temp = head;
        ListNode* prev = NULL;
        int nodes = list.size();
        int rem = 0;
        for (int idx = nodes - 1; idx >= 0; idx--) {
          int current = (list[idx] * 2 + rem);
          int val = current % 10;
          rem = current / 10;
           if (temp) {
            temp->val = val;
          } else {
            prev->next = new ListNode(val);
            temp = prev;
          }
          
          prev = temp;
          temp = temp->next;
        }
      
        if (rem) {
          prev->next = new ListNode(1);
        }
      
        return reverse(head);
        
    }
};