// https://leetcode.com/problems/sort-list/

class Solution {
public:
    // Time: O(N * logN) | Space: O(N)
    // N = number of nodes
    ListNode* sortList(ListNode* head) {
        vector<int> nums;
        ListNode* temp = head;
        while (temp != NULL) {
          nums.push_back(temp->val);  
          temp = temp->next;
        }
      
        sort(nums.begin(), nums.end());
        temp = head;
        int pos = 0;
      
        while (temp != NULL) {
          temp->val = nums[pos];
          pos += 1;
          temp = temp->next;
        }
      
        return head;
    }
};