
class Solution {
public:
    // Time: O(N * maxLen) | Space: O(N * maxLen);
    // N = number of lists
    // maxLen = longest length present in the lists
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int N = lists.size();
      
        ListNode* newListHead = new ListNode(-1);
        ListNode* runningNode = newListHead;
        bool isNodeLeft = true;
      
        while (isNodeLeft) {
          int minVal = INT_MAX;
          int pos = -1;
          isNodeLeft = false;
          for (int idx = 0; idx < N; idx++) {
            ListNode* node = lists[idx];
            if (node) {
              isNodeLeft = true;
              if (node->val < minVal) {
                pos = idx;
                minVal = node->val; 
              }
            }
          }
          
          if (pos != -1) {
            runningNode->next = new ListNode(minVal);
            runningNode = runningNode->next;
            ListNode* node = lists[pos];
            lists[pos] = node->next;
          }
        }
      
        return newListHead->next;
    }
};