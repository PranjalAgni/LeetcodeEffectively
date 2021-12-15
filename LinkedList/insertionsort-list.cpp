class Solution {
private:
  vector<int> getVectorFromList(ListNode* head) {
    vector<int> nums;
    while (head != NULL) {
      nums.push_back(head->val);
      head = head->next;
    }
    
    return nums;
  }  
public:
    // Time: O(N * log(N)) | Space: O(N)
    ListNode* insertionSortList(ListNode* head) {
        if (!head) return head;
        vector<int> nums = getVectorFromList(head);
        sort(nums.begin(), nums.end());
        ListNode* temp = head;
        int pos = 0;
        while (temp != NULL) {
          temp->val = nums[pos];
          pos += 1;
          temp = temp->next;
        }
      
        return head;
    }
};