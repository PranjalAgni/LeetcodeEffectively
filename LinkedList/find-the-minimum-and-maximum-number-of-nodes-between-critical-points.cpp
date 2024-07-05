// https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/
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
 // Time: O(N) | Space: O(1)
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* temp = head;
        int closest = INT_MAX;
        int farthest = INT_MIN;
        int firstCriticalPoint = -1;
        int secondCriticalPoint = -1;
        int pos = 2;
      
        while (temp->next != NULL && temp->next->next != NULL) {
          int a = temp->val;
          int b = temp->next->val;
          int c = temp->next->next->val;
          if (((b < a) && (b < c)) || ((b > a) && (b > c))) {
            if (firstCriticalPoint == -1) {
              firstCriticalPoint = pos;
            } else if (secondCriticalPoint == -1) {
              farthest = max(farthest, pos - firstCriticalPoint);
              closest = min(closest, pos - firstCriticalPoint);
              secondCriticalPoint = pos;
            } else {
              farthest = max(farthest, pos - firstCriticalPoint);
              closest = min(closest, pos - secondCriticalPoint);
              secondCriticalPoint = pos;
            }
          }
          
          temp = temp->next;
          pos += 1;
        }
      
        farthest = (farthest == INT_MIN) ? -1 : farthest;
        closest = (closest == INT_MAX) ? -1 : closest;
      
       
        return {closest, farthest};
    }
};